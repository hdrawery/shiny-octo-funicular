#include "img_dao.h"

const QString ImgDao::tableName="image";
IState ImgDao::choose=IMG_NORMAL;
QString ImgDao::currentDate="";
int ImgDao::start=0;
bool ImgDao::insert(Img &single)
{
    QStringList key,value;
    key<<"i_name";
    key<<"s_path";
    key<<"s_time";

    value.append(single.getImgName());
    value.append(single.getSavePath());
    value.append(single.getSaveDate());


    bool ret=DBUtil::getInstance().insert(tableName,value,key);

    return ret;
}

void ImgDao::getSql(QVector<Img> &info, QString date)
{
    QStringList list;
    if(date=="")
    {
        if(choose!=IMG_NORMAL)
        {
            start=0;
            choose=IMG_NORMAL;
        }
        //qDebug()<<tableName<<endl;
        DBUtil::getInstance().findByPage(tableName,list,9,start);
    }
    else
    {
        if(choose!=IMG_SEARCH)
        {
            start=0;
            choose=IMG_SEARCH;
        }
        //qDebug()<<date<<endl;
        if(currentDate=="")
        {
            currentDate=date;
        }
        else
        {
            if(currentDate!=date)
            {
                currentDate=date;
                start=0;
            }
        }

        QString conditon="s_time='"+currentDate+"'";
        DBUtil::getInstance().findByPage(tableName,list,9,start,conditon);
    }
    if(list.size()==1&&list[0]=="")
    {
        return ;
    }
    start+=9;
    int i;
    for(i=0;i<list.size();i+=3)
    {
        //qDebug()<<list.at(i)<<endl;

        Img img(list.at(i),list.at((i+1)),list.at((i+2)));
        info.push_back(img);
    }
}

int ImgDao::getCount(QString date)
{
    int count;

    if(date=="")
    {
       count=DBUtil::getInstance().getTableCount(tableName);
    }
    else
    {
        QString conditon="s_time='"+date+"'";
        count=DBUtil::getInstance().getTableCount(tableName,conditon);
    }

    return count;
}

int ImgDao::reset()
{
    start=0;
}
