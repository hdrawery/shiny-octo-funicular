#include "dbutil.h"
DBUtil *DBUtil::instance=nullptr;
QMutex DBUtil::mutex;
sqlite3 *DBUtil::db;

DBUtil &DBUtil::getInstance()
{
    if(instance==nullptr)
    {
        //mutex.lock();
        if(instance==nullptr)
        {
            instance=new DBUtil();
            openDataBase();
        }
        //mutex.unlock();
    }
    return *instance;
}

bool DBUtil::insert(QString tableName, QStringList &values, QStringList &key)
{
    if(values.size()!=key.size())
    {
        return false;
    }
    QString sql_insert="insert into "+tableName+"(";
    for(int i=0;i<key.size();i++)
    {
        sql_insert+=key.at(i);
        if(i!=key.size()-1)
        {
            sql_insert+=",";
        }
    }
    sql_insert+=") values(";
    for(int i=0;i<key.size();i++)
    {

        sql_insert+="'";
        sql_insert+=values.at(i);
        sql_insert+="'";
        if(i!=key.size()-1)
        {
            sql_insert+=",";
        }
     }
     sql_insert+=");";
     cout<<sql_insert.toStdString()<<endl;
     char **temp=nullptr;
     int row=0,col=0;
     ret=sqlite3_get_table(db,sql_insert.toUtf8().toStdString().c_str(),&temp,&row,&col,nullptr);
     sqlite3_free_table(temp);
     //cout<<ret<<endl;
     if(ret==SQLITE_OK)
     {
         return true;

     }
     else
     {
        return false;
     }
}

bool DBUtil::update(QString tableName, QStringList &values, QStringList &key)
{
    if(values.size()!=key.size())
    {
       return false;
    }
    QString sql_insert="insert or replace into "+tableName+"(";
    for(int i=0;i<key.size();i++)
    {
        sql_insert+=key.at(i);
        if(i!=key.size()-1)
        {
            sql_insert+=",";
        }
    }
    sql_insert+=") values(";
    for(int i=0;i<key.size();i++)
    {
        if(i==0)
        {
            sql_insert+=values.at(0);
        }
        else
        {
            sql_insert+="'";
            sql_insert+=values.at(i);
            sql_insert+="'";
        }

        if(i!=key.size()-1)
        {
            sql_insert+=",";
        }
    }
    sql_insert+=");";
    cout<<sql_insert.toStdString()<<endl;


    char **temp=nullptr;
    int row=0,col=0;

    ret=sqlite3_get_table(db,sql_insert.toUtf8().toStdString().c_str(),&temp,&row,&col,nullptr);
    sqlite3_free_table(temp);
    //cout<<ret<<endl;
    if(ret==SQLITE_OK)
    {
        return true;

    }
    else
    {
       return false;
    }
}

QStringList DBUtil::findAll(QString tableName, QStringList &list)
{
    QString sql_find="select * from "+tableName+";";
    char **temp=nullptr;
    int row=0,col=0;

    ret=sqlite3_get_table(db,sql_find.toUtf8().toStdString().c_str(),&temp,&row,&col,nullptr);
    //int start=col;

    if(ret==SQLITE_OK)
    {
        if(row>=1)
        {
            //cout<<row<<"123"<<endl;
            for(int i=col+1;i<(row+1)*col;i++)
            {
                if(i%col==0)
                {
                    continue;
                }
                QString s= QString(QString::fromLocal8Bit(temp[i]));
                qDebug()<<s<<endl;
                list<<s;
            }
//            cout<<temp[col+1]<<endl;
//            cout<<temp[col+2]<<endl;
//            cout<<temp[col+3]<<endl;

//            QString s1= QString(QString::fromLocal8Bit(temp[col+1]));
//            QString s2= QString(QString::fromLocal8Bit(temp[col+2]));
//            QString s3= QString(QString::fromLocal8Bit(temp[col+3]));
//            QString s4= QString(QString::fromLocal8Bit(temp[col+4]));

//            list<<s1;
//            list<<s2;
//            list<<s3;
//            list<<s4;
        }
        else
        {
            string str="";
            list.append(QString::fromStdString(str));
        }
     }
     sqlite3_free_table(temp);

     return list;
}



QStringList DBUtil::findByPage(QString tableName, QStringList &list, int length, int start, QString condition)
{
    QString sql_find;
    if(condition=="")
    {
        sql_find="select * from "+tableName+" limit "+QString::number(length)+" offset "+QString::number(start)+";";
    }
    else
    {
        sql_find="select * from "+tableName+" where "+condition+" limit "+QString::number(length)+" offset "+QString::number(start)+";";
    }
    char **temp=nullptr;
    int row=0,col=0;
    qDebug()<<sql_find<<endl;
    ret=sqlite3_get_table(db,sql_find.toUtf8().toStdString().c_str(),&temp,&row,&col,nullptr);
    if(ret==SQLITE_OK)
    {
        if(row>=1)
        {
            //cout<<row<<"123"<<endl;


            for(int i=col;i<(row+1)*col;i++)
            {
                if(i%col==0)
                {
                    continue;
                }


                QString s= QString(QString::fromLocal8Bit(temp[i]));
                list<<s;
            }

        }
        else
        {
            string str="";
            list.append(QString::fromStdString(str));
        }
     }
     sqlite3_free_table(temp);

     return list;
}

int DBUtil::getTableCount(QString tableName, QString condition)
{
    QString sql="select count(*) from "+tableName+";";
    if(condition=="")
    {
        sql="select count(*) from "+tableName+";";
    }
    else
    {
        sql="select count(*) from "+tableName+" where "+condition+";";
    }
    char **temp=nullptr;
    int row=0,col=0;
    QString s;
    //qDebug()<<sql<<endl;
    ret=sqlite3_get_table(db,sql.toUtf8().toStdString().c_str(),&temp,&row,&col,nullptr);
    if(ret==SQLITE_OK)
    {
        if(row>=1)
        {
            //cout<<row<<"123"<<endl;


            s=temp[1];

        }

     }
     sqlite3_free_table(temp);

     return s.toInt();
}

DBUtil::DBUtil()
{

}

bool DBUtil::openDataBase()
{
    int ret=sqlite3_open("../db/driver_record.db",&db);
    //QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForLocale(codec);
    if(ret==SQLITE_OK)
    {
        //cout<<"open"<<endl;
        return true;
    }
    else
    {
        return false;
    }
}

void DBUtil::closeDataBase()
{
    sqlite3_close(db);
}
