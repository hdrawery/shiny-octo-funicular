#ifndef TRANSCODEPAGECONTROLLER_H
#define TRANSCODEPAGECONTROLLER_H
#include "cache.h"
#include "fdecode.h"

#include <QObject>

class TranscodePageController:public QObject
{
    Q_OBJECT
public:
    static TranscodePageController &getInstance();
signals:
   // void sendVideoName(QString);
    void videoOverview(QStringList,QStringList);
    void videoSize(int);
    void sendCount(int);
public slots:
    void previousVideo();
    void nextVideo();
    void getVideoInfo();
    void getVideoSearchInfo();
    void setVideoDate(QString);
    void transcodeThread(QString name,QString savePath,QString format);
    void setProgress(int index);
    void clearVideo();
    //void getVideoName(int index);
private:
    TranscodePageController();
    static TranscodePageController *instance;
    QList<Video> video_tempList;
    static int video_pageNow;
    QString searchVideoDate;
    VState choose1;
    Fdecode *trans_fd;
    int maxNum;

};

#endif // TRANSCODEPAGECONTROLLER_H
