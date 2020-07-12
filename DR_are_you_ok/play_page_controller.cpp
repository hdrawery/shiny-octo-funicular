#include "play_page_controller.h"
PlayPageController *PlayPageController::instance=nullptr;
PlayPageController &PlayPageController::getInstance()
{
    if(instance==nullptr)
    {
        instance=new PlayPageController();
    }
    return *instance;
}

void PlayPageController::startFdThread()
{
    Video *v=Cache::getInstance().findVideoPath(sources);
    if(v==nullptr)
    {
        return ;
    }

    qDebug()<<"fd start"<<endl;
    QStringList list;
    Cache::getInstance().getSetting(list);

    fd=new Fdecode(list.at(0),list.at(1),SOURCES);
    connect(fd,SIGNAL(sendImg(QImage)),this,SLOT(getImg(QImage)));
    connect(fd,SIGNAL(playFinished()),this,SLOT(playFinished()));

//    isNatural=true;

    qDebug()<<"first"<<endl;

    QString path=v->getSavePath()+"/"+sources+".h264";

    fd->setSource(path);
    fd->start();

    emit videoSize(v->getSize());
}

void PlayPageController::setSources(QString sources)
{
    this->sources=sources;
    startFdThread();
}
void PlayPageController::getImg(QImage img)
{
    emit sendImg(img);
}

void PlayPageController::restart()
{

    if(!fd->isFinished())
    {
        qDebug()<<"restart"<<endl;
        fd->restart();
    }
    else
    {
        startFdThread();
        //将界面二倍速图标复原
        emit replay();
    }

}

void PlayPageController::changeSpeed(int mult)
{
    fd->setMult(mult);
}

void PlayPageController::playFinished()
{
//    if(isNatural)
//    {
        emit finished();
//    }

}

void PlayPageController::saveImg(QImage img)
{
    //获取路径
    QStringList list;
    Cache::getInstance().getSetting(list);

    QString current_date = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
    QString path=list.at(1)+"/"+current_date+".jpg";
    img.save(path);

    //保存到数据库
    saveImgToDB(current_date,current_date.mid(0,10),list.at(1));
    //saveImgToDB(current_date,list.at(1),current_date.mid(0,10));

}

void PlayPageController::findPrevious(QString name)
{
    //暂停现在播放的
//    isNatural=false;
    fd->stop();
    //查找新的视频信息
    Video *v=Cache::getInstance().findPreviousVideo(name);
    if(v==nullptr)
    {
        return ;
    }
    this->sources=v->getName();

    //判断是否结束
    while(!fd->isFinished())
    {

    }
    //结束了就重新new一个

    QString path=v->getSavePath()+"/"+sources+".h264";
    qDebug()<<path<<endl;
    fd->setSource(path);

    fd->start();
    //isNatural=true;
    //启动就暂停
    //pause();
    //重置进度条 视频名 和 播放按钮
    emit videoSize(v->getSize());
    emit videoInit(sources);


}

void PlayPageController::findLast(QString name)
{
//    isNatural=false;
    fd->stop();
    Video *v=Cache::getInstance().findLastVideo(name);
    if(v==nullptr)
    {
        return ;
    }
    this->sources=v->getName();


    while(!fd->isFinished())
    {

    }


    qDebug()<<"first"<<endl;

    QString path=v->getSavePath()+"/"+sources+".h264";

    fd->setSource(path);

    fd->start();
    //isNatural=true;
    //pause();
    emit videoSize(v->getSize());
    emit videoInit(sources);

}

void PlayPageController::transcode()
{
    Video *v=Cache::getInstance().findVideoPath(sources);
    if(v==nullptr)
    {
        return ;
    }

    qDebug()<<"transFd start"<<endl;
    QStringList list;
    Cache::getInstance().getSetting(list);
    //this->sources=name;
    transFd=new Fdecode(list.at(0),list.at(1),TRANSCODE);

    QString path=v->getSavePath()+"/"+sources+".h264";
    //qDebug()<<path<<endl;
    transFd->setSource(path);
    transFd->start();


}
void PlayPageController::saveImgToDB(QString imgName, QString date, QString saveImg)
{
    Img img(imgName,saveImg,date);
    ImgDao::insert(img);
}
void PlayPageController::pause()
{
    if(fd->isRunning())
    {
        qDebug()<<"pause"<<endl;
        fd->pause();
    }
 }
PlayPageController::PlayPageController()
{

}
