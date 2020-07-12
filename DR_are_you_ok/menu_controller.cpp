#include "menu_controller.h"
MenuController *MenuController::instance=nullptr;
int MenuController::video_pageNow=0;
int MenuController::img_pageNow=0;
MenuController &MenuController::getInstance()
{
    if(instance==nullptr)
    {
        instance=new MenuController();
    }
    return *instance;
}

void MenuController::getVideoInfo()
{
    video_tempList.clear();
    if(choose1!=VIDEO_NORMAL)
    {
        video_pageNow=0;
        choose1=VIDEO_NORMAL;
    }
    QStringList name,coverPath;

    Cache::getInstance().getVideo(video_tempList,video_pageNow*9);
    //qDebug()<<"start:"<<pageNow*9<<endl;
    if(video_tempList.size()==0)
    {
        //emit videoOverview(name,coverPath);
        return;
    }
    for(int i=0;i<video_tempList.size();i++)
    {
       // qDebug()<<tempList[i].getCoverImg()<<endl;
        name<<video_tempList[i].getName();
        coverPath<<video_tempList[i].getCoverImg();
    }

    emit videoOverview(name,coverPath);
}

void MenuController::previousVideo()
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

void MenuController::nextVideo()
{

    maxVideoNum=Cache::getInstance().getVideoSum();
    if(video_pageNow*9<maxVideoNum)
    {
        video_pageNow++;
//        if(maxVideoNum/9==video_pageNow||maxVideoNum/9==(video_pageNow-1))
//        {
//            Cache::getInstance().putVideo();
//            maxVideoNum=Cache::getInstance().getVideoSum();
//        }
    }

    if(choose1==VIDEO_NORMAL)
    {
        getVideoInfo();
    }
    else if(choose1==VIDEO_SEARCH)
    {
        getVideoSearchInfo();
    }

}

void MenuController::getVideoMaxCount()
{
    int count=Cache::getInstance().getVideoSum();

    emit sendVideoSum(count);
}

void MenuController::setVideoDate(QString date)
{
    searchVideoDate=date;
    Cache::getInstance().getSearchVideoSum(searchVideoDate);
    getVideoSearchInfo();
}

void MenuController::getVideoSearchInfo()
{
    if(choose1!=VIDEO_SEARCH)
    {
        choose1=VIDEO_SEARCH;
        video_pageNow=0;
    }
    video_tempList.clear();
    QStringList name,coverPath;
    //qDebug()<<"start:"<<pageNow<<endl;
    Cache::getInstance().getSearchVideo(video_tempList,video_pageNow*9,searchVideoDate);

    maxVideoNum=Cache::getInstance().getVideoSearchSum();
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

void MenuController::clearVideo()
{
    Cache::getInstance().videoListClear();
    choose1=VIDEO_NORMAL;

    video_pageNow=0;
}

void MenuController::clearImg()
{
     Cache::getInstance().imgListClear();

     choose2=IMG_NORMAL;
     img_pageNow=0;
}

void MenuController::getImgInfo()
{
    img_tempList.clear();
    if(choose2!=IMG_NORMAL)
    {
        img_pageNow=0;
        choose2=IMG_NORMAL;
    }
    QStringList name,coverPath;
    Cache::getInstance().getImg(img_tempList,img_pageNow*9);
    //qDebug()<<"start:"<<pageNow*9<<endl;
    if(img_tempList.size()==0)
    {
        //emit videoOverview(name,coverPath);
        return;
    }
    for(int i=0;i<img_tempList.size();i++)
    {

        name<<img_tempList[i].getImgName();
        QString path=img_tempList[i].getSavePath()+"/"+img_tempList[i].getImgName()+".jpg";
        //qDebug()<<path<<endl;
        coverPath<<path;
    }

    emit imgOverview(name,coverPath);
}

void MenuController::previousImg()
{
    if(img_pageNow>0)
    {
        img_pageNow--;
        if(choose2==IMG_NORMAL)
        {
            getImgInfo();
        }
        else if(choose2==IMG_SEARCH)
        {
            getImgSearchInfo();
        }
    }
    else
    {
        //qDebug()<<"pageNow"<<pageNow<<endl;
    }
}

void MenuController::nextImg()
{
    if(img_pageNow*9<maxImgNum)
    {
        img_pageNow++;
    }

    if(choose2==IMG_NORMAL)
    {
        getImgInfo();
    }
    else if(choose2==IMG_SEARCH)
    {
        getImgSearchInfo();
    }
}

void MenuController::getImgMaxCount()
{
    int count=Cache::getInstance().getImgSum();

    emit sendImgSum(count);
}

void MenuController::setImgDate(QString date)
{
    searchImgDate=date;
    Cache::getInstance().getSearchImgSum(searchImgDate);
    getImgSearchInfo();
}

void MenuController::getImgSearchInfo()
{
    if(choose2!=IMG_SEARCH)
    {
        choose2=IMG_SEARCH;
        img_pageNow=0;
    }
    img_tempList.clear();
    QStringList name,coverPath;

    //qDebug()<<"start:"<<pageNow<<endl;
    Cache::getInstance().getSearchImg(img_tempList,img_pageNow*9,searchImgDate);
    maxImgNum=Cache::getInstance().getImgSearchSum();
    //qDebug()<<"start:"<<endl;
    if(img_tempList.size()==0)
    {

        //emit imgOverview(name,coverPath);
        return;
    }
    for(int i=0;i<img_tempList.size();i++)
    {
        //qDebug()<<img_tempList[i].getImgName()<<endl;

        name<<img_tempList[i].getImgName();
        QString path=img_tempList[i].getSavePath()+"/"+img_tempList[i].getImgName()+".jpg";
        coverPath<<path;

    }

    emit imgOverview(name,coverPath);
}

MenuController::MenuController()
{
    choose1=VIDEO_NORMAL;
    choose2=IMG_NORMAL;
    maxVideoNum=Cache::getInstance().getVideoSum();
    maxImgNum=Cache::getInstance().getImgSum();
}
