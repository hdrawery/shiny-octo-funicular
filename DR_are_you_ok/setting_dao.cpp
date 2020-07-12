#include "setting_dao.h"


const QString SettingDao::tableName="setting";

bool SettingDao::update(QString video, QString img, int itv, QString name)
{
    QStringList key,value;
    key<<"s_id";
    key<<"v_path";
    key<<"i_path";
    key<<"a_interval";
    key<<"c_name";
    value.append("1");
    value.append(video);
    value.append(img);
    value.append(QString::number(itv));
    value.append(name);

    bool ret=DBUtil::getInstance().update(tableName,value,key);

    return ret;
}


void SettingDao::getSql(QStringList &info)
{

    DBUtil::getInstance().findAll(tableName,info);

}



