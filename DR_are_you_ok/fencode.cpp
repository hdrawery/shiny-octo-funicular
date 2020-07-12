#include "fencode.h"


Fencode::Fencode()
{
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));
}
void Fencode::setInitInfo(int width, int height, QString savePath)
{
    this->width=width;
    this->height=height;
    this->savePath=savePath;
}

void Fencode::setInterval(int interval)
{
    this->interval=interval;
}
QString Fencode::initEncode()
{
    av_register_all();

    int res=-1;
    const char *outfile="";

    QString current_date = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
    fileName=current_date;
    QString name=savePath+"/"+current_date+".h264";

    outfile=name.toStdString().c_str();
    qDebug()<<name<<endl;
    AVOutputFormat *avOfmat=av_guess_format(nullptr,outfile,nullptr);
    if(nullptr==avOfmat)
    {
        qDebug()<<"guess failed!"<<endl;
        return nullptr;
    }

    fmatc=avformat_alloc_context();
    fmatc->oformat=avOfmat;
    res=avio_open(&fmatc->pb,outfile,AVIO_FLAG_WRITE);
    if(res<0)
    {
        qDebug()<<"avio_open failed!"<<endl;
        //Cache::getInstance().optFrame(OUT);
        //Cache::getInstance().getImgName();
        return nullptr;
    }
    AVStream *outStream=avformat_new_stream(fmatc,nullptr);
    if(nullptr==outStream)
    {
        qDebug()<<"new Stream failed!"<<endl;
        return nullptr;
    }

    //init data

    //codec=avcodec_alloc_context3(nullptr);
    //avcodec_parameters_to_context(codec,outStream->codecpar);
    codec=outStream->codec;
    codec->width=width;
    codec->height=height;
    codec->bit_rate=4000000;//the number of bit per sec
    codec->time_base={1,25};// - encoding: MUST be set by user.
    codec->framerate={25,1};
    codec->gop_size=10;//the number of pic in per group
    codec->qmax=51;
    codec->qmin=10;
    codec->max_b_frames=0;
    codec->pix_fmt=AV_PIX_FMT_YUV420P;
    codec->codec_type=AVMEDIA_TYPE_VIDEO;
    codec->codec_id=avOfmat->video_codec;


    AVCodec *code=avcodec_find_encoder(codec->codec_id);
    if(nullptr==code)
    {
        qDebug()<<"find encoder failed!"<<endl;
        return nullptr;
    }

    res=avcodec_open2(codec,code,nullptr);
    if(res!=0)
    {
        qDebug()<<"open encoder failed!"<<endl;
        return nullptr;
    }

    res=avformat_write_header(fmatc,nullptr);

    if(res<0)
    {
        qDebug()<<"write header failed!"<<endl;
        return nullptr;
    }
    avpkt=av_packet_alloc();

    Cache::getInstance().putImgName(fileName);
    return name;
}
void Fencode::write_tailer()
{
     av_write_trailer(fmatc);
     avio_close(fmatc->pb);
     avformat_free_context(fmatc);
}
void Fencode::run()
{
    QString ret=nullptr;
    while(ret==nullptr)
    {
        ret=initEncode();
    }
    this->state=RUN;
    count=0;

    while(1)
    {
        if(state==STOP)
        {
            write_tailer();
            emit sendFileName(fileName,count);
            break;
        }
        if(count>interval)
        {
            write_tailer();
            emit sendFileName(fileName,count);
            QString ret=nullptr;
            while(ret==nullptr)
            {
                ret=initEncode();
            }
            usleep(500);
            emit saveCover();
            count=0;

        }
       encodeFrame();

    }
    //write_tailer();

}

void Fencode::stop()
{
    this->state=STOP;
}


Fencode::~Fencode()
{

}
bool Fencode::encodeFrame()
{

    AVFrame *frame=Cache::getInstance().optFrame(OUT);
    //qDebug()<<"start encode"<<endl;
    if(frame==nullptr)
    {
        return false;
    }

    int res=-1;
    frame->pts++;
    res=avcodec_send_frame(codec,frame);

    if(res<0)
    {
       qDebug()<<"send frame failed!"<<endl;
       //Cache::getInstance().popFrame();
       return false;
    }

    count++;
    while(res>=0)
    {
       res=avcodec_receive_packet(codec,avpkt);

       if(res==AVERROR(EAGAIN)||res==AVERROR_EOF)
       {
           return false;
       }
       else if(res<0)
       {
            qDebug()<<"receive acpkt failed!"<<endl;
            return false;
       }
       avpkt->stream_index=0;
       av_interleaved_write_frame(fmatc,avpkt);
        //qDebug()<<ret<<endl;
       //av_frame_free(&frame);
       av_packet_unref(avpkt);

     }

    return true;
}
