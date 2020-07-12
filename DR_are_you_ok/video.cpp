#include "video.h"


Video::Video()
{

}

Video::Video(QString name, QString date, QString path, QString cover, int size)
{
    this->name=name;
    this->saveDate=date;
    this->savePath=path;
    this->coverImg=cover;
    this->size=size;
}

Video::Video(const Video &v)
{
    this->name=v.name;
    this->saveDate=v.saveDate;
    this->savePath=v.savePath;
    this->coverImg=v.coverImg;
    this->size=v.size;
}

QString Video::getName()
{
    return name;
}

QString Video::getSaveDate()
{
    return saveDate;
}

QString Video::getSavePath()
{
    return savePath;
}

QString Video::getCoverImg()
{
    return coverImg;
}

int Video::getSize()
{
    return size;
}
