#ifndef SETTINGDAO_H
#define SETTINGDAO_H

#include "dbutil.h"
#include <QString>

class SettingDao
{
public:
    static bool update(QString video, QString img, int itv, QString name);
    static void getSql(QStringList &info);
private:
    static const QString tableName;

};

#endif // SETTINGDAO_H
