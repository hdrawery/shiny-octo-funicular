#include "main_page_controller.h"




MainPageController *MainPageController::instance=nullptr;
MainPageController &MainPageController::getInstance()
{

    if(instance==nullptr)
    {
        instance=new MainPageController();
    }
    return *instance;
}

QString MainPageController::monthInEN(QString mon)
{
    if(mon=="1")
    {
        return "Jan";
    }
    else if(mon=="2")
    {
        return "Feb";
    }
    else if(mon=="3")
    {
        return "Mar";
    }
    else if(mon=="4")
    {
       return "Apr";
    }
    else if(mon=="5")
    {
       return "May";
    }
    else if(mon=="6")
    {
       return "Jun";
    }
    else if(mon=="7")
    {
       return "Jul";
    }
    else if(mon=="8")
    {
       return "Aug";
    }
    else if(mon=="9")
    {
       return "Sept";
    }
    else if(mon=="10")
    {
       return "Oct";
    }
    else if(mon=="11")
    {
       return "Nov";
    }
    else if(mon=="12")
    {
       return "Dec";
    }
    else
    {
       return "";
    }
}
void MainPageController::getTime()
{
    QDateTime time=QDateTime::currentDateTime();
    QString year=time.toString("yyyy");
    QString day=time.toString("d");
    QString month=time.toString("M");
    month=monthInEN(month);

    QString current=month+" "+day+","+year;

    emit findCurrentDate(current);
}

void MainPageController::saveVideoToDB(QString videoName, QString date, QString saveVideo, QString saveImg,int count)
{
    saveImgToDB(videoName,date,saveImg);
    QString path=saveImg+"/"+videoName+".jpg";
    Video v(videoName,date,saveVideo,path,count);
    VideoDao::insert(v);
}

void MainPageController::saveImgToDB(QString imgName, QString date, QString saveImg)
{
    Img img(imgName,saveImg,date);
    ImgDao::insert(img);
}

void MainPageController::saveImg(QImage img)
{
    QStringList list;
    Cache::getInstance().getSetting(list);
    QString current_date = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
    QString path=list.at(1)+"/"+current_date+".jpg";
    img.save(path);
    saveImgToDB(current_date,current_date.mid(0,10),list.at(1));
}

void MainPageController::startFdThread()
{
    qDebug()<<"fd start"<<endl;

    QStringList list;
    Cache::getInstance().getSetting(list);

    fd=new Fdecode(list.at(0),list.at(1),CAM);
    connect(fd,SIGNAL(sendImg(QImage)),this,SLOT(getImg(QImage)));
    connect(fd,SIGNAL(saveVideoInfo(QString,QString,QString,QString,int)),this,SLOT(saveVideoToDB(QString,QString,QString,QString,int)));
    //connect(fd,SIGNAL(stopWorking()),this,SLOT(deleteThread()));
    qDebug()<<"first"<<endl;


    int interval=list.at(2).toInt();
    fd->setCam(list.at(3),interval);
    fd->start();



}
void MainPageController::getImg(QImage img)
{
    emit sendImg(img);
}

void MainPageController::exitSys()
{
    stopFdThread();
    qApp->exit(0);
}

void MainPageController::stopFdThread()
{
    qDebug()<<"stop"<<endl;
    if(fd->isRunning())
    {
        fd->stop();
    }

}

void MainPageController::noSendImg()
{
    fd->changePage();
}

void MainPageController::restart()
{

    if(fd==nullptr)
    {
        startFdThread();
    }
    else
    {
        fd->restart();
    }
}
MainPageController::MainPageController()
{
    fd=nullptr;
}
