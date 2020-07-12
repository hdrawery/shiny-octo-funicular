#include "video_dao.h"

const QString VideoDao::tableName="video";
VState VideoDao::choose=VIDEO_NORMAL;
QString VideoDao::currentDate="";
int VideoDao::start=0;
bool VideoDao::insert(Video &single)
{
    QStringList key,value;
    key<<"v_name";
    key<<"s_time";
    key<<"s_path";
    key<<"c_img";
    key<<"v_size";

    value.append(single.getName());
    value.append(single.getSaveDate());
    value.append(single.getSavePath());
    value.append(single.getCoverImg());
    value.append(QString::number(single.getSize()));

    bool ret=DBUtil::getInstance().insert(tableName,value,key);

    return ret;
}

void VideoDao::getSql(QVector<Video> &info, QString date)
{
    QStringList list;
    if(date=="")
    {
        if(choose!=VIDEO_NORMAL)
        {
            start=0;
            choose=VIDEO_NORMAL;
        }
        DBUtil::getInstance().findByPage(tableName,list,9,start);
    }
    else
    {
        if(choose!=VIDEO_SEARCH)
        {
            start=0;
            choose=VIDEO_SEARCH;
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
    for(i=0;i<list.size();i+=5)
    {
        //qDebug()<<list.at(i)<<endl;
        int size=list.at(i+4).toInt();
        Video v(list.at(i),list.at((i+1)),list.at((i+2)),list.at((i+3)),size);
        info.push_back(v);
    }

}

int VideoDao::getCount(QString date)
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

void VideoDao::reset()
{
    start=0;
}


