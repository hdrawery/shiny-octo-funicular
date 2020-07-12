#ifndef IMGDAO_H
#define IMGDAO_H

#include "dbutil.h"
#include "img.h"
enum IState{IMG_NORMAL,IMG_SEARCH};
class ImgDao
{
public:
    static bool insert(Img &single);
    static void getSql(QVector<Img> &info,QString date="");
    static int getCount(QString date="");
    static int reset();

private:
    static const QString tableName;
    static int start;
    static IState choose;
    static QString currentDate;
};

#endif // IMGDAO_H
