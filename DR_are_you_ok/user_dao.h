#ifndef USERDAO_H
#define USERDAO_H

#include "dbutil.h"
#include "user.h"

#include <QString>

class UserDao
{
public:
    static bool insert(QString name, QString pwd);
    static void getSql(QStringList &list);
    static int getCount();
private:
    static const QString tableName;
};

#endif // USERDAO_H
