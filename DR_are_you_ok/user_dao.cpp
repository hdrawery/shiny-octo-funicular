#include "user_dao.h"

const QString UserDao::tableName="user";

bool UserDao::insert(QString name, QString pwd)
{
    QStringList key,value;
    key<<"u_name";
    key<<"u_pwd";

    value.append(name);
    value.append(pwd);


    bool ret=DBUtil::getInstance().insert(tableName,value,key);

    return ret;
}

void UserDao::getSql(QStringList &list)
{
    QStringList tempList;
    DBUtil::getInstance().findAll(tableName,tempList);
    if(tempList.size()==1&&tempList[0]=="")
    {
        return ;
    }
    int i;
    for(i=0;i<tempList.size();i+=3)
    {
        //qDebug()<<list.at(i)<<endl;
//        int size=list.at(i+4).toInt();
//        Video v(list.at(i),list.at((i+1)),list.at((i+2)),list.at((i+3)),size);
//        info.push_back(v);

        list<<tempList.at(i);
        list<<tempList.at(i+1);

    }
}

int UserDao::getCount()
{
    int count;

    count=DBUtil::getInstance().getTableCount(tableName);

    return count;
}
