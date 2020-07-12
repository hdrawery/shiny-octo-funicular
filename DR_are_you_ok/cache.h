#ifndef CACHE_H
#define CACHE_H

#include "setting_dao.h"
#include "video_dao.h"
#include "img_dao.h"
#include "user_dao.h"



extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavutil/pixfmt.h>
    #include <libavutil/imgutils.h>
    #include <libavdevice/avdevice.h>
}
#include <QMutex>
#include <QString>
#include <QQueue>
#include <QHash>
enum Opt{IN,OUT};
class Cache
{
public:
    static Cache &getInstance();
    void setSetting(QString video, QString img, int itv, QString name);
    void getSetting(QStringList &list);
    QString getImgName();
    AVFrame* optFrame(Opt type,AVFrame *frame=nullptr);
    void putImgName(QString name);
    void queueClear();
    void popFrame();

    void putVideo(QString date="");
    void getVideo(QList<Video> &list,int start,int len=9);
    int getVideoSum();
    void getSearchVideoSum(QString date="");
    void getSearchVideo(QList<Video> &list,int start,QString date,int len=9);
    Video* findVideoPath(QString video);
    Video* findPreviousVideo(QString video);
    Video* findLastVideo(QString video);
    int getVideoSearchSum();
    void videoListClear();

    void imgListClear();

    void putImg(QString date="");
    void getImg(QList<Img> &list,int start,int len=9);
    int getImgSum();
    void getSearchImgSum(QString date="");
    void getSearchImg(QList<Img> &list,int start,QString date,int len=9);
    Img* findImgPath(QString img);
    Img* findPreviousImg(QString img);
    Img* findLastImg(QString img);
    int getImgSearchSum();

    int getUserNum();
    void putUser(QString name,QString pwd);
    User* getUser(int id);
private:
    int findVideo(QString video);
    int findImg(QString img);
    Cache();
    static Cache *instance;
    static QMutex mutex;
    QMutex frameMutex;
    QString imgPath;
    QString videoPath;
    int interval;
    QString camName;
    QQueue<AVFrame *>frameQueue;
    QQueue<QString>imgNameQueue;


    QVector<Video> videoList;
    QVector<Video> videoSearchList;

    QVector<Img> imgList;
    QVector<Img> imgSearchList;

    int videoSum;
    int videoSearchSum;

    int imgSum;
    int imgSearchSum;

    int userNum;
    QHash<int,User> userMap;

};

#endif // CACHE_H
