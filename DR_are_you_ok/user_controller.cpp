#include "user_controller.h"


UserController *UserController::instance=nullptr;
UserController &UserController::getInstance()
{
    if(instance==nullptr)
    {
        instance=new UserController();
    }
    return *instance;
}

bool UserController::getIsLogined()
{
    return isLogined;
}

void UserController::setIsLogined(bool isLogined)
{
    this->isLogined=isLogined;
}

void UserController::getNewId()
{
    int count=Cache::getInstance().getUserNum();
    emit newId(1000+count);
}

void UserController::regist(QString id, QString name, QString pwd)
{
    if(id==""||name==""||pwd=="")
    {
        emit registIsSuccess(false);
    }
    else
    {
        QString MD5NewPasswd = QCryptographicHash::hash(pwd.toLatin1(), QCryptographicHash::Md5).toHex();
        Cache::getInstance().putUser(name,MD5NewPasswd);
        bool ret=UserDao::insert(name,MD5NewPasswd);
        emit registIsSuccess(ret);
    }
}

void UserController::checkId(QString id)
{
    int ID=id.toInt();

    User* u=Cache::getInstance().getUser(ID);
    if(u==nullptr)
    {
        emit isIdExist(false);
    }
    else
    {
        emit isIdExist(true);
    }
}

void UserController::loginCheck(QString id, QString pwd)
{
    if(id==""||pwd=="")
    {
        emit checkRet(false);
    }
    int ID=id.toInt();
    cout<<ID<<endl;
    if(ID-1000>=Cache::getInstance().getUserNum())
    {
         emit checkRet(false);
         return ;
    }
    User* u=Cache::getInstance().getUser(ID);
    QString MD5NewPasswd = QCryptographicHash::hash(pwd.toLatin1(), QCryptographicHash::Md5).toHex();
    if(u->getPwd()==MD5NewPasswd)
    {
        qDebug()<<"true"<<endl;
        emit checkRet(true);
    }
    else
    {
        emit checkRet(false);
    }
}


UserController::UserController()
{
    isLogined=false;
}
