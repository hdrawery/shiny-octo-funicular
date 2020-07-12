#ifndef DBUTIL_H
#define DBUTIL_H

#include "sqlite3.h"

#include <QMutex>
#include <QString>
#include <QVariantMap>
#include <string>
#include <QTextCodec>
#include <QDebug>
#include <iostream>
using namespace std;
class DBUtil
{
public:
    static DBUtil &getInstance();
    bool insert(QString tableName,QStringList &values,QStringList &key);
    bool update(QString tableName,QStringList &values,QStringList &key);
    QStringList findAll(QString tableName,QStringList &list);
    QStringList findByPage(QString tableName,QStringList &list,int length,int start,QString condition="");
    int getTableCount(QString tableName,QString condition="");
private:
    DBUtil();
    static bool openDataBase();
    static void closeDataBase();
    static DBUtil *instance;
    static QMutex mutex;
    static sqlite3 *db;
    int ret;
};

#endif // DBUTIL_H
