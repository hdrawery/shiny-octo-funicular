#include "transcode_page_controller.h"
int TranscodePageController::video_pageNow=0;
TranscodePageController *TranscodePageController::instance=nullptr;
TranscodePageController &TranscodePageController::getInstance()
{
    if(instance==nullptr)
    {
        instance=new TranscodePageController();
    }
    return *instance;
}

void TranscodePageController::previousVideo()
{
    if(video_pageNow>0)
    {
        video_pageNow--;
        if(choose1==VIDEO_NORMAL)
        {
            getVideoInfo();
        }
        else if(choose1==VIDEO_SEARCH)
        {
           getVideoSearchInfo();
        }
    }
    else
    {
        //qDebug()<<"pageNow"<<pageNow<<endl;
    }
}

void TranscodePageController::nextVideo()
{
    if(video_pageNow*3<maxNum)
    {
        video_pageNow++;
       // qDebug()<<video_pageNow<<endl;
        if(choose1==VIDEO_NORMAL)
        {
            getVideoInfo();
        }
        else if(choose1==VIDEO_SEARCH)
        {
            getVideoSearchInfo();
        }
    }


}

void TranscodePageController::getVideoInfo()
{
    maxNum=Cache::getInstance().getVideoSum();
    video_tempList.clear();
    if(choose1!=VIDEO_NORMAL)
    {
        video_pageNow=0;
        choose1=VIDEO_NORMAL;
    }
    QStringList name,coverPath;
    Cache::getInstance().getVideo(video_tempList,video_pageNow*3,3);
    //qDebug()<<"start:"<<pageNow*9<<endl;
    if(video_tempList.size()==0)
    {
        //emit videoOverview(coverPath);

        return;
    }
    for(int i=0;i<video_tempList.size();i++)
    {
        //qDebug()<<video_tempList[i].getCoverImg()<<endl;
        name<<video_tempList[i].getName();
        coverPath<<video_tempList[i].getCoverImg();

    }

    emit videoOverview(name,coverPath);
}
void TranscodePageController::setVideoDate(QString date)
{
    searchVideoDate=date;
    Cache::getInstance().getSearchVideoSum(searchVideoDate);
    getVideoSearchInfo();
}

void TranscodePageController::transcodeThread(QString name, QString savePath, QString format)
{
    Video *v=Cache::getInstance().findVideoPath(name);
    if(v==nullptr)
    {
        return ;
    }
    emit videoSize(v->getSize()-11);
    qDebug()<<"transFd start"<<endl;
    QStringList list;
    Cache::getInstance().getSetting(list);
    //this->sources=name;
    trans_fd=new Fdecode(list.at(0),list.at(1),TRANSCODE);
    connect(trans_fd,SIGNAL(progress(int)),this,SLOT(setProgress(int)));
    QString path=v->getSavePath()+"/"+name+".h264";
    //qDebug()<<savePath<<" "<<format<<endl;
    trans_fd->setSource(path);
    trans_fd->setDstPath(savePath,format);
    trans_fd->start();
}

void TranscodePageController::setProgress(int index)
{
    emit sendCount(index);
}

void TranscodePageController::clearVideo()
{
    Cache::getInstance().videoListClear();
    choose1=VIDEO_NORMAL;

    video_pageNow=0;
}
void TranscodePageController::getVideoSearchInfo()
{
    if(choose1!=VIDEO_SEARCH)
    {
        choose1=VIDEO_SEARCH;
        video_pageNow=0;
    }
    video_tempList.clear();
    QStringList name,coverPath;
    //qDebug()<<"start:"<<pageNow<<endl;
    Cache::getInstance().getSearchVideo(video_tempList,video_pageNow*3,searchVideoDate);

    maxNum=Cache::getInstance().getVideoSearchSum();
    //qDebug()<<"start:"<<pageNow*9<<endl;
    if(video_tempList.size()==0)
    {
        //emit videoOverview(name,coverPath);
        return;
    }
    for(int i=0;i<video_tempList.size();i++)
    {
        //qDebug()<<tempList[i].getCoverImg()<<endl;
        name<<video_tempList[i].getName();
        coverPath<<video_tempList[i].getCoverImg();
    }

    emit videoOverview(name,coverPath);
}

//void TranscodePageController::getVideoName(int index)
//{
//    QString name=video_tempList[index].getName();
//    emit sendVideoName(name);
//}

TranscodePageController::TranscodePageController()
{
     choose1=VIDEO_NORMAL;
     maxNum=Cache::getInstance().getVideoSum();
}
