#ifndef VIDEODAO_H
#define VIDEODAO_H

#include "dbutil.h"
#include "video.h"
enum VState{VIDEO_NORMAL,VIDEO_SEARCH};
class VideoDao
{
public:
    static bool insert(Video &single);
    static void getSql(QVector<Video> &info,QString date="");
    static int getCount(QString date="");
    static void reset();
private:
    static const QString tableName;
    static int start;
    static VState choose;
    static QString currentDate;
};

#endif // VIDEODAO_H
