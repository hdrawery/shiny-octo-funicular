#include "cache.h"

#include <QDateTime>
Cache *Cache::instance=nullptr;
QMutex Cache::mutex;

Cache &Cache::getInstance()
{
    if(instance==nullptr)
    {
        mutex.lock();
        if(instance==nullptr)
        {
            instance=new Cache();
        }
        mutex.unlock();
    }
    return *instance;
}
void Cache::getSetting(QStringList &list)
{
    list<<videoPath;
    list<<imgPath;
    list<<QString::number(interval);
    list<<camName;
}



QString Cache::getImgName()
{
    if(imgNameQueue.isEmpty())
    {
        return "";
    }
    QString name=imgNameQueue.front();
    imgNameQueue.dequeue();
    return name;
}

AVFrame *Cache::optFrame(Opt type, AVFrame *frame)
{
    QMutexLocker locker(&frameMutex);
    if(type==OUT)
    {
        if(frameQueue.isEmpty())
        {

            return nullptr;
        }
        AVFrame *frame=frameQueue.front();
        frameQueue.dequeue();
        return frame;
    }
    else
    {
        frameQueue.enqueue(frame);
        return nullptr;
    }
}

void Cache::putImgName(QString name)
{

    imgNameQueue.enqueue(name);
}



void Cache::queueClear()
{
    frameQueue.clear();
    imgNameQueue.clear();
}

void Cache::popFrame()
{
    if(!frameQueue.isEmpty())
    {
       frameQueue.dequeue();
    }

}

void Cache::putVideo(QString date)
{
    if(date=="")
    {
        VideoDao::getSql(videoList);
        //videoSum=VideoDao::getCount();
    }
    else
    {
//        QDateTime dateTime(QDateTime::currentDateTime());
//        QString qStr = dateTime.toString("yyyy-MM-dd");
        VideoDao::getSql(videoSearchList,date);
//        if(qStr==date)
//        {
//            videoSearchSum=VideoDao::getCount(date);
//        }
    }

}



void Cache::getVideo(QList<Video> &list, int start,int len)
{
    if(start>=videoSum)
    {
        //putVideo();
        return;
    }

    int length=videoList.size();
    if(length<=start)
    {
        //qDebug()<<length<<","<<videoSum<<endl;
        putVideo();
        if(length==videoList.size())
        {
            return;
        }
    }

    length=videoList.size();
    for(int i=0;i<len;i++)
    {
        if(start+i>=length)
        {
            break;
        }
        qDebug()<<videoList[start+i].getName()<<endl;
        list.push_back(videoList[start+i]);
    }
}

int Cache::getVideoSum()
{
    videoSum=VideoDao::getCount();
    //qDebug()<<videoSum<<endl;
    return videoSum;
}

void Cache::getSearchVideoSum(QString date)
{
    videoSearchSum=VideoDao::getCount(date);
    //qDebug()<<videoSearchSum<<endl;
}

void Cache::getSearchVideo(QList<Video> &list, int start, QString date,int len)
{
    if(start>=videoSearchSum)
    {
       // putVideo(date);
        return;
    }
    int length=videoSearchList.size();
    //qDebug()<<length<<endl;
    if(length>0&&date!=videoSearchList[0].getSaveDate())
    {

        videoSearchList.clear();
        length=0;
    }
    if(length<=start)
    {
        putVideo(date);
        if(length==videoSearchList.size())
        {
            //qDebug()<<videoSearchList.size()<<endl;
            return;
        }
    }

    length=videoSearchList.size();
    for(int i=0;i<len;i++)
    {
        if(start+i>=length)
        {
            break;
        }
        //qDebug()<<videoSearchList[start+i].getName()<<endl;
        list.push_back(videoSearchList[start+i]);
    }
}

Video* Cache::findVideoPath(QString video)
{

    int index=findVideo(video);
    if(index==-1)
    {
        return nullptr;
    }
    else
    {
        return &videoList[index];
    }

}

Video *Cache::findPreviousVideo(QString video)
{
    int index=findVideo(video);
    if(index<=0)
    {
        return nullptr;
    }
    else
    {
        return &videoList[index-1];
    }
}

Video *Cache::findLastVideo(QString video)
{
    int index=findVideo(video);
    qDebug()<<index<<endl;
    if(index==-1||index==videoSum-1)
    {
        return nullptr;
    }
    else
    {

        return &videoList[index+1];
    }
}

int Cache::getVideoSearchSum()
{
    return videoSearchSum;
}

void Cache::videoListClear()
{
    videoList.clear();
    videoSearchList.clear();
    videoSum=VideoDao::getCount();
    videoSearchSum=0;
    VideoDao::reset();
}

void Cache::imgListClear()
{
    imgList.clear();
    imgSearchList.clear();
    imgSum=ImgDao::getCount();
    imgSearchSum=0;
    ImgDao::reset();
}

void Cache::putImg(QString date)
{
    if(date=="")
    {
        ImgDao::getSql(imgList);
        //imgSum=ImgDao::getCount();
    }
    else
    {
//        QDateTime dateTime(QDateTime::currentDateTime());
//        QString qStr = dateTime.toString("yyyy-MM-dd");
        ImgDao::getSql(imgSearchList,date);
//        if(date==qStr)
//        {
//            imgSearchSum=ImgDao::getCount(date);
//        }
    }
}

void Cache::getImg(QList<Img> &list, int start,int len)
{
    if(start>=imgSum)
    {
       // putImg();
        return;
    }
    int length=imgList.size();
    if(length<=start)
    {
        putImg();
        if(length==imgList.size())
        {
            return;
        }
    }

    length=imgList.size();
    for(int i=0;i<len;i++)
    {
        if(start+i>=length)
        {
            break;
        }
        list.push_back(imgList[start+i]);
    }
}

int Cache::getImgSum()
{
    imgSum=ImgDao::getCount();
    return imgSum;
}

void Cache::getSearchImgSum(QString date)
{
    imgSearchSum=ImgDao::getCount(date);
}

void Cache::getSearchImg(QList<Img> &list, int start, QString date,int len)
{
    if(start>=imgSearchSum)
    {
       // putImg(date);
        return;
    }
    int length=imgSearchList.size();
    //qDebug()<<length<<endl;
    if(length>0&&date!=imgSearchList[0].getSaveDate())
    {

        imgSearchList.clear();
        length=0;
    }
    if(length<=start)
    {
        putImg(date);
        if(length==imgSearchList.size())
        {
            //qDebug()<<videoSearchList.size()<<endl;
            return;
        }
    }

    length=imgSearchList.size();
    for(int i=0;i<len;i++)
    {
        if(start+i>=length)
        {
            break;
        }
        //qDebug()<<imgSearchList[start+i].getImgName()<<endl;
        list.push_back(imgSearchList[start+i]);
    }
}

Img *Cache::findImgPath(QString img)
{
    int index=findImg(img);
    if(index==-1)
    {
        return nullptr;
    }
    else
    {
        return &imgList[index];

    }
}

Img *Cache::findPreviousImg(QString img)
{
    qDebug()<<"img before:"<<img<<endl;
    int index=-1;
    int i=0;
    bool flag=false;
    while(imgList.size()<imgSum)
    {
        for(;i<imgList.size();i++)
        {

            QString path=imgList[i].getSavePath()+"/"+imgList[i].getImgName()+".jpg";

            if(path==img)
            {
                index=i;
                flag=true;
            }
        }
        putImg();
    }
    if(!flag)
    {
        for(;i<imgList.size();i++)
        {
            QString path=imgList[i].getSavePath()+"/"+imgList[i].getImgName()+".jpg";
            if(path==img)
            {
                index=i;
                break;
            }
        }
    }
    qDebug()<<index<<endl;
    if(index<=0)
    {
        return nullptr;
    }
    else
    {
        return &imgList[index-1];
    }
}

Img *Cache::findLastImg(QString img)
{
    qDebug()<<"img last:"<<img<<endl;
    int index=-1;
    int i=0;
    bool flag=false;
    while(imgList.size()<imgSum)
    {
        for(;i<imgList.size();i++)
        {

            QString path=imgList[i].getSavePath()+"/"+imgList[i].getImgName()+".jpg";

            if(path==img)
            {
                index=i;
                break;
                flag=true;
            }
        }
        putImg();
    }
    if(!flag)
    {
        for(;i<imgList.size();i++)
        {
            QString path=imgList[i].getSavePath()+"/"+imgList[i].getImgName()+".jpg";
            if(path==img)
            {
                index=i;
                break;
            }
        }
    }


    qDebug()<<index<<endl;
    if(index==-1||index==imgSum-1)
    {
        return nullptr;
    }
    else
    {

        return &imgList[index+1];
    }
}

int Cache::getImgSearchSum()
{
    return imgSearchSum;
}

int Cache::getUserNum()
{
    return userNum;
}

void Cache::putUser(QString name, QString pwd)
{
    int new_id=userNum+1000;
    userMap.insert(new_id,User(new_id,name,pwd));
    userNum++;
}

User *Cache::getUser(int id)
{
    if(id-1000>=userNum)
    {
        return  nullptr;
    }
    else
    {
        qDebug()<<userMap[id].getName()<<endl;
        return &userMap[id];
    }

}



int Cache::findVideo(QString video)
{
    int i=0;
    while(videoList.size()<videoSum)
    {
        for(;i<videoList.size();i++)
        {
            if(videoList[i].getName()==video)
            {
                return i;
            }
        }
        putVideo();
    }
    for(;i<videoList.size();i++)
    {
        if(videoList[i].getName()==video)
        {
            return i;
        }
    }
    return -1;
}

int Cache::findImg(QString img)
{
    int i=0;
    while(imgList.size()<imgSum)
    {
        for(;i<imgList.size();i++)
        {

            //QString path=imgList[i].getSavePath()+"/"+imgList[i].getImgName()+".jpg";

            if(imgList[i].getImgName()==img)
            {
                return i;
            }
        }
        putImg();
    }
    for(;i<imgList.size();i++)
    {
        if(imgList[i].getImgName()==img)
        {
            return i;
        }
    }
    return -1;
}





void Cache::setSetting(QString video, QString img, int itv, QString name)
{
    videoPath=video;
    imgPath=img;
    interval=itv;
    camName=name;
}
Cache::Cache()
{
    videoSum=VideoDao::getCount();
    imgSum=ImgDao::getCount();
    userNum=UserDao::getCount();

    QStringList info;
    SettingDao::getSql(info);
    if(info.size()>1)
    {
        videoPath=info.at(0);
        imgPath=info.at(1);
        interval=info.at(2).toInt();
        camName=info.at(3);
    }
    else
    {
        videoPath="";
        imgPath="";
        interval=0;
        camName="";
    }
    QStringList list;

    UserDao::getSql(list);
    int j=0;
    for(int i=0;i<userNum;i++)
    {
        int new_id=i+1000;
        //qDebug()<<list.at(j)<<" "<<list.at(j+1)<<endl;
        userMap.insert(new_id,User(new_id,list.at(j),list.at(j+1)));
        j+=2;
    }

}
