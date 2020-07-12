#ifndef IMGPAGECONTROLLER_H
#define IMGPAGECONTROLLER_H

#include "cache.h"

#include <QObject>



class ImgPageController:public QObject
{
    Q_OBJECT
public:
    static ImgPageController &getInstance();
protected:

signals:
    void setImg(QString);
public slots:
    void getPrevious(QString sources);
    void getLast(QString sources);
    void getImgPath(QString name);
private:
    ImgPageController();
    static ImgPageController *instance;


};

#endif // IMGPAGECONTROLLER_H
