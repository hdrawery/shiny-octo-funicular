#ifndef VIDEO_H
#define VIDEO_H

#include <QString>



class Video
{
public:
    Video();
    Video(QString name,QString date,QString path,QString cover,int size);
    Video(const Video &v);
    QString getName();
    QString getSaveDate();
    QString getSavePath();
    QString getCoverImg();
    int getSize();
private:
    QString name;
    QString saveDate;
    QString savePath;
    QString coverImg;
    int size;
};

#endif // VIDEO_H
