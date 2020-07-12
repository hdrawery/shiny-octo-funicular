#ifndef USER_H
#define USER_H

#include <QString>



class User
{
public:
    User();
    User(int id,QString name,QString pwd);
    User(const User& me);
    int getId();
    QString getName();
    QString getPwd();
private:
    QString name;
    QString pwd;
    int id;
};

#endif // USER_H
