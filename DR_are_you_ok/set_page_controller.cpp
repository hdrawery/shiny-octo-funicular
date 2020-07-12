#include "set_page_controller.h"
SetPageController *SetPageController::instance=nullptr;
SetPageController &SetPageController::getInstance()
{
    if(instance==nullptr)
    {
        instance=new SetPageController();
    }
    return *instance;
}

QString SetPageController::deviceName(int index)
{
    if(index<0)
    {
        return QString();
    }
    return QCameraInfo::availableCameras().at(index).description();
}

void SetPageController::checkCamInfo()
{
    QStringList list;
    Cache::getInstance().getSetting(list);
    bool isNull;
    if(list.at(0)==""||list.at(1)==""||list.at(2)=="0")
    {
        isNull=true;
    }
    else
    {
        isNull=false;
    }
    emit checkCamRet(isNull);
}

void SetPageController::getCamName()
{
    QString name=deviceName(0);
     emit findCamName(name);
}

void SetPageController::setCam(QString video, QString img, QString itv, QString name)
{
    int interval=itv.toInt();
    SettingDao::update(video,img,interval,name);
    Cache::getInstance().setSetting(video,img,interval,name);
}

void SetPageController::getCamInfo()
{
    QStringList list;
    Cache::getInstance().getSetting(list);
    if(list.at(0)==""||list.at(1)==""||list.at(2)=="0")
    {
        emit findCamInfo("","","");
    }
    else
    {
        emit findCamInfo(list.at(0),list.at(1),list.at(2));
    }
}

SetPageController::SetPageController()
{

}
