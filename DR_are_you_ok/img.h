#ifndef IMG_H
#define IMG_H

#include <QString>



class Img
{
public:
    Img();
    Img(QString name,QString path,QString date);
    Img(const Img &i);
    QString getImgName();
    QString getSaveDate();
    QString getSavePath();
private:
    QString name;
    QString saveDate;
    QString savePath;
};

#endif // IMG_H
