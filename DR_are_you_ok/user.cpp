#include "user.h"

User::User()
{

}

User::User(int id, QString name, QString pwd)
{
    this->id=id;
    this->name=name;
    this->pwd=pwd;
}

User::User(const User &me)
{
    this->id=me.id;
    this->name=me.name;
    this->pwd=me.pwd;
}

int User::getId()
{
    return  id;
}

QString User::getName()
{
    return name;
}

QString User::getPwd()
{
    return pwd;
}
