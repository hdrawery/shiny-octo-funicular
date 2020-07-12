#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "cache.h"

#include <QObject>
#include <bits/functional_hash.h>
#include <QCryptographicHash>
class UserController:public QObject
{
    Q_OBJECT
public:
    static UserController &getInstance();
    bool getIsLogined();
signals:
    void newId(int);
    void registIsSuccess(bool);
    void isIdExist(bool);
    void checkRet(bool);
public slots:
    void setIsLogined(bool isLogined);
    void getNewId();
    void regist(QString id,QString name,QString pwd);
    void checkId(QString id);
    void loginCheck(QString id,QString pwd);
private:
    UserController();
    static UserController *instance;
    bool isLogined;
};

#endif // USERCONTROLLER_H
