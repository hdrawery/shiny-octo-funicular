#ifndef MAINPAGECONTROLLER_H
#define MAINPAGECONTROLLER_H

#include "cache.h"
#include "fdecode.h"

#include <QObject>
#include <QDateTime>
#include <QImage>
#include <QApplication>
class MainPageController:public QObject
{
    Q_OBJECT
public:
    static MainPageController &getInstance();
protected:
    QString monthInEN(QString mon);
signals:
    void findCurrentDate(QString);
    void sendImg(QImage);
public slots:
    void getTime();
    void saveVideoToDB(QString videoName,QString date,QString saveVideo,QString saveImg,int count);
    void saveImgToDB(QString imgName,QString date,QString saveImg);
    void saveImg(QImage img);
    void startFdThread();
    void getImg(QImage img);
    void exitSys();
    void stopFdThread();
    void noSendImg();
    void restart();
private:
    MainPageController();
    static MainPageController *instance;
    Fdecode *fd;

};

#endif // MAINPAGECONTROLLER_H
