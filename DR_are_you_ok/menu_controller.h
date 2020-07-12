#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "cache.h"

#include <QObject>

class MenuController:public QObject
{
    Q_OBJECT
public:
    static MenuController &getInstance();
signals:
    void videoOverview(QStringList,QStringList);
    void sendVideoSum(int);
    void imgOverview(QStringList,QStringList);
    void sendImgSum(int);
public slots:
    void getVideoInfo();
    void previousVideo();
    void nextVideo();
    void getVideoMaxCount();
    void setVideoDate(QString date);
    void getVideoSearchInfo();
    void clearVideo();
    void clearImg();

    void getImgInfo();
    void previousImg();
    void nextImg();
    void getImgMaxCount();
    void setImgDate(QString date);
    void getImgSearchInfo();

private:
    MenuController();
    static MenuController *instance;
    QList<Video> video_tempList;
    QList<Img> img_tempList;
    static int video_pageNow;
    static int img_pageNow;
    QString searchVideoDate;
    QString searchImgDate;
    VState choose1;
    IState choose2;
    int maxVideoNum;
    int maxImgNum;
};

#endif // MENUCONTROLLER_H
