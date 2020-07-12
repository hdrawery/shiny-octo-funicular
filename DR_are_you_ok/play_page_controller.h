#ifndef PLAYPAGECONTROLLER_H
#define PLAYPAGECONTROLLER_H

#include "fdecode.h"

#include <QObject>



class PlayPageController:public QObject
{
    Q_OBJECT
public:
    static PlayPageController &getInstance();
protected:
    void saveImgToDB(QString imgName, QString date, QString saveImg);
signals:
    void findCurrentDate(QString);
    void sendImg(QImage);
    void finished();
    void replay();
    void videoSize(int);
    void videoInit(QString);
public slots:
    void startFdThread();
    void setSources(QString sources);
    void pause();
    void getImg(QImage img);
    void restart();
    void changeSpeed(int mult);
    void playFinished();
    void saveImg(QImage img);
    void findPrevious(QString name);
    void findLast(QString name);
    void transcode();
private:
    PlayPageController();
    static PlayPageController *instance;
    Fdecode *fd;
    QString sources;
    Fdecode *transFd;
    //bool isNatural;
};

#endif // PLAYPAGECONTROLLER_H
