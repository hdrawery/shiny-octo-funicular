#include "fdecode.h"


Fdecode::Fdecode(QString videoSavePath, QString imgSavePath, FdType type)
{
    this->videoSave=videoSavePath;
    this->imgSave=imgSavePath;
    this->choose=type;
    //connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));
    mult=1;
    fev=new Fencode();
    connect(fev,SIGNAL(sendFileName(QString,int)),this,SLOT(SendCamInfo(QString,int)));
    connect(fev,SIGNAL(saveCover()),this,SLOT(setCountZero()));
}
void Fdecode::setCam(QString name,int interval)
{
    if(choose==CAM)
    {
       camName=name;
       this->interval=interval;
       fev->setInterval(interval);

    }
}

void Fdecode::setDstPath(QString path, QString format)
{
    dstPath=path;
    dstFormat=format;
}


void Fdecode::setSource(QString source)
{
    if(choose==SOURCES||choose==TRANSCODE)
    {
        this->source=source;
    }
}

void Fdecode::setMult(int m)
{
    if(choose==SOURCES)
    {
        mult=m;
    }
}

void Fdecode::changePage()
{
    state=NOIMG;
}
void Fdecode::stop()
{
    this->state=STOP;
    qDebug()<<"stop"<<endl;
    if(choose==CAM)
    {
        fev->stop();
    }


}

void Fdecode::pause()
{
    if(choose==SOURCES)
    {
       this->state=PAUSE;
    }
}

void Fdecode::restart()
{

    this->state=RUN;

}


//void Fdecode::finishSignal()
//{
//    emit allStopWork();
//}
Fdecode::~Fdecode()
{
    Cache::getInstance().queueClear();
}
void Fdecode::SendCamInfo(QString fileName,int count)
{
    emit saveVideoInfo(fileName,fileName.mid(0,10),videoSave,imgSave,count);
}

void Fdecode::clear()
{
    av_frame_unref(picture);
    avcodec_close(codecContext);
    av_packet_unref(acPkt);
}

void Fdecode::setCountZero()
{
    count=0;
}
void Fdecode::registerFFMPEG()
{
    av_register_all();
    avdevice_register_all();
    avformat_network_init();

}
void Fdecode::to_RGB(uint8_t *buffer)
{
    QImage img((uchar *)buffer,codecContext->width,codecContext->height,QImage::Format_RGB32);
    if(count==0&&choose==CAM)
    {

        QString name=Cache::getInstance().getImgName();
        if(name!="")
        {
            QString path=imgSave+"/"+name+".jpg";
            img.save(path);
        }

    }
    if(state!=NOIMG)
    {
       emit sendImg(img);
    }
    count++;
    //qDebug()<<"send"<<endl;

}

void Fdecode::H264_to_MP4()
{
    int len=source.size();

    QString path;
    if(dstPath=="")
    {
        path=source.mid(0,len-4)+".mp4";
    }
    else
    {
        path=dstPath+"."+dstFormat;
    }
    qDebug()<<path<<endl;
    const char *outfile=path.toStdString().c_str();
    AVFormatContext *outFmat=avformat_alloc_context();
    AVOutputFormat *avOfmat=av_guess_format(nullptr,outfile,nullptr);
    if(nullptr==avOfmat)
    {
        qDebug()<<"guess failed!"<<endl;
        return;
    }

    outFmat->oformat=avOfmat;

    int res=avio_open(&outFmat->pb,outfile,AVIO_FLAG_WRITE);
    if(res<0)
    {
        qDebug()<<"write header failed!"<<endl;
        return;
    }

    AVStream *inStream=fmatC->streams[videoIndex];
    AVStream *outStream=avformat_new_stream(outFmat,nullptr);
    if(nullptr==outStream)
    {
        qDebug()<<"new Stream failed!"<<endl;
        return;
    }

    outStream->codec=inStream->codec;
    outStream->codec->codec_tag=0;
    outStream->codec->flags=inStream->codec->flags;
    outStream->codec->time_base.num=inStream->avg_frame_rate.den;
    outStream->codec->time_base.den=inStream->avg_frame_rate.num;

    res=avformat_write_header(outFmat,nullptr);
    if(res<0)
    {
        qDebug()<<"write header failed!"<<endl;
        return;
    }

    AVPacket *pkt=av_packet_alloc();

    int frameConut=0;
    while(av_read_frame(fmatC,pkt)>=0)
    {
        frameConut++;
        if(dstPath!="")
        {
            emit progress(frameConut);
        }
        qDebug()<<"frameConut:"<<frameConut<<endl;
        if(pkt->stream_index==videoIndex)
        {
            if(AV_NOPTS_VALUE==pkt->pts)
            {
                AVRational timeBasel=inStream->time_base;
                int64_t calc_duration=(double)AV_TIME_BASE
                            /av_q2d(inStream->r_frame_rate);
                pkt->pts=(double)frameConut*calc_duration/
                            (double)(av_q2d(timeBasel)*AV_TIME_BASE);
                pkt->dts=pkt->pts;
                pkt->duration=calc_duration/
                            (double)(av_q2d(timeBasel)*AV_TIME_BASE);
            }
            pkt->pts=av_rescale_q_rnd(pkt->pts,
                                        inStream->time_base,
                                        outStream->time_base,
                                        (AVRounding)(AV_ROUND_INF|AV_ROUND_PASS_MINMAX));
            pkt->dts=av_rescale_q_rnd(pkt->pts,
                                        inStream->time_base,
                                        outStream->time_base,
                                        (AVRounding)(AV_ROUND_INF|AV_ROUND_PASS_MINMAX));
            pkt->duration=av_rescale_q(pkt->duration,
                                        inStream->time_base,
                                        outStream->time_base);
            pkt->pos=-1;
            pkt->flags|=AV_PKT_FLAG_KEY;
            pkt->stream_index=0;
            av_interleaved_write_frame(outFmat,pkt);
        }
        av_packet_unref(pkt);
    }
    av_write_trailer(outFmat);
    avcodec_close(outFmat->streams[videoIndex]->codec);
    //av_freep(outFmat->streams[videoIndex]->codec);
    avio_close(outFmat->pb);
    av_free(outFmat);
    avformat_close_input(&fmatC);
    av_free(fmatC);
    av_packet_free(&pkt);
}
void Fdecode::init()
{
    fmatC=avformat_alloc_context();
    int res=-99;

    if(CAM==choose)
    {
        //AVInputFormat *IfmatC=av_find_input_format("video4linux2");
        //res=avformat_open_input(&fmatC,"/dev/video0",IfmatC,nullptr);
        AVInputFormat *IfmatC = av_find_input_format("dshow");
        AVDictionary* options =nullptr;
        av_dict_set_int(&options, "rtbufsize",3041280*10, 0);
        QString name="video="+camName;
        res=avformat_open_input(&fmatC,name.toStdString().c_str(),IfmatC,&options);
     }
     else if(choose==SOURCES||choose==TRANSCODE)
     {
        //qDebug()<<source<<endl;
        res=avformat_open_input(&fmatC,source.toStdString().c_str(),nullptr,nullptr);

     }
     if(res<0)
     {
         qDebug()<<"AVFormatContext don't be allocated!";
         return;
     }



     res=avformat_find_stream_info(fmatC,nullptr);
     if(res<0)
     {
        qDebug()<<"Not find info!";
        return;
     }
     videoIndex=-1;
     for(int i=0;i<fmatC->nb_streams;i++)//2 streams info:picture and video
     {
        if(fmatC->streams[i]->codecpar->codec_type==AVMEDIA_TYPE_VIDEO)
        {
            videoIndex=i;
            break;
        }
     }
     if(-1==videoIndex)
     {
        qDebug()<<"Not find video info!";
        return;
     }
}
bool Fdecode::initDecode()
{
    init();

    codecContext=avcodec_alloc_context3(nullptr);
    avcodec_parameters_to_context(codecContext,fmatC->streams[videoIndex]->codecpar);
    codec=avcodec_find_decoder(codecContext->codec_id);
    if(nullptr==codec)
    {
        qDebug()<<"Not find decode info!";
        return false;
    }

    int res=avcodec_open2(codecContext,codec,nullptr);
    if(res!=0)
    {
        qDebug()<<"Open code failed!";
        return false;
    }
    acPkt=av_packet_alloc();
    size=codecContext->width*codecContext->height;
    av_new_packet(acPkt,size);
    got_picture_ptr=-1;

    picture=av_frame_alloc();

    return true;
}

void Fdecode::run()
{
    this->state=RUN;
    registerFFMPEG();
//    if(choose==TRANSCODE)
//    {
//        init();


//    }
//    else
//    {
        bool ret=initDecode();
        if(!ret)
        {
            state=STOP;
            qDebug()<<"no find"<<endl;
            return;
        }
//    }
    count=0;
    SwsContext *sws_context_img,*sws_context_h264;
    uint8_t *buffer_img;
    AVFrame *dstFrame_h264,*dstFrame_img;

    dstFrame_img=av_frame_alloc();
    dstFrame_h264=av_frame_alloc();

    int numByte_img=av_image_get_buffer_size(AV_PIX_FMT_RGB32,codecContext->width,codecContext->height,1);//YUVFrame size
    buffer_img=(uint8_t *)av_malloc(numByte_img*sizeof(uint8_t));
    av_image_fill_arrays(dstFrame_img->data,dstFrame_img->linesize,buffer_img,AV_PIX_FMT_RGB32,codecContext->width,codecContext->height,1);


    sws_context_img=sws_getContext(codecContext->width,codecContext->height,codecContext->pix_fmt,
                                  codecContext->width,codecContext->height,AV_PIX_FMT_RGB32,SWS_BICUBIC,nullptr,nullptr,nullptr);
    sws_context_h264=sws_getContext(codecContext->width,codecContext->height,codecContext->pix_fmt,
                                            codecContext->width,codecContext->height,AV_PIX_FMT_YUV420P,SWS_BICUBIC,nullptr,nullptr,nullptr);


    if(choose==TRANSCODE)
    {
       H264_to_MP4();
       qDebug()<<"finished"<<endl;
       state=STOP;
       clear();
       return ;
    }
     if(choose==CAM)
     {


         int numByte_h264=av_image_get_buffer_size(AV_PIX_FMT_YUV420P,codecContext->width,codecContext->height,1);//YUVFrame size
         uint8_t *buffer_h264=(uint8_t *)av_malloc(numByte_h264*sizeof(uint8_t));
         av_image_fill_arrays(dstFrame_h264->data,dstFrame_h264->linesize,buffer_h264,AV_PIX_FMT_YUV420P,codecContext->width,codecContext->height,1);

         dstFrame_h264->width=codecContext->width;
         dstFrame_h264->height=codecContext->height;
         dstFrame_h264->format=codecContext->pix_fmt;
         dstFrame_h264->pts=0;

     }

     if(choose==CAM)
     {
         fev->setInitInfo(codecContext->width,codecContext->height,videoSave);

         fev->start();

     }
     while(choose!=TRANSCODE&&state!=STOP)
     {
         while(state!=STOP&&state!=PAUSE&&av_read_frame(fmatC,acPkt)==0)
         {

             if(acPkt->stream_index==videoIndex)
             {
                 avcodec_send_packet(codecContext,acPkt);
                 got_picture_ptr=avcodec_receive_frame(codecContext,picture);

                 if(!got_picture_ptr)
                 {

                     if(choose==SOURCES||choose==CAM)
                     {

                          sws_scale(sws_context_img,picture->data,picture->linesize,0,picture->height,dstFrame_img->data,dstFrame_img->linesize);
                          to_RGB(buffer_img);


                     }
                     if(choose==CAM)
                     {
                         sws_scale(sws_context_h264,picture->data,picture->linesize,0,picture->height,dstFrame_h264->data,dstFrame_h264->linesize);
                        // if(!fev->isFinished())
                        // {
                            Cache::getInstance().optFrame(IN,dstFrame_h264);
                            msleep(2);
                        // }

                     }

                     if(choose==SOURCES)
                     {
                         if(mult==1)
                         {
                            msleep(40);
                         }
                         else
                         {
                            msleep(0);
                         }
                     }
                 }

             }

             av_packet_unref(acPkt);
         }
         if(state!=PAUSE&&state!=STOP)//就是读完了
         {
             break;
         }

     }

     av_frame_unref(dstFrame_img);

     av_frame_unref(dstFrame_h264);


     if(choose==SOURCES&&state!=STOP)
     {
         emit playFinished();
     }
     state=STOP;
     qDebug()<<"finished"<<endl;
     clear();
}
