#include "img.h"


Img::Img()
{

}

Img::Img(QString name, QString path,QString date)
{
    this->name=name;
    this->saveDate=date;
    this->savePath=path;
}

Img::Img(const Img &i)
{
    name=i.name;
    saveDate=i.saveDate;
    savePath=i.savePath;
}

QString Img::getImgName()
{
    return name;
}

QString Img::getSaveDate()
{
    return saveDate;
}

QString Img::getSavePath()
{
    return savePath;
}
