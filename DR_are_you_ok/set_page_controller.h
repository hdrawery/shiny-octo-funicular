#ifndef SETPAGECONTROLLER_H
#define SETPAGECONTROLLER_H

#include "cache.h"

#include <QObject>
#include <QtMultimedia/QCameraInfo>


class SetPageController:public QObject
{
    Q_OBJECT
public:
    static SetPageController &getInstance();
protected:
    QString deviceName(int index);
signals:
    void checkCamRet(bool);
    void findCamName(QString);
    void findCamInfo(QString,QString,QString);
public slots:
    void checkCamInfo();
    void getCamName();
    void setCam(QString video,QString img,QString itv,QString name);
    void getCamInfo();
private:
    SetPageController();
    static SetPageController *instance;
};

#endif // SETPAGECONTROLLER_H
