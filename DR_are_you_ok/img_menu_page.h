#ifndef IMGMENUPAGE_H
#define IMGMENUPAGE_H

#include "img_table.h"

#include <QCalendarWidget>
#include <QPushButton>
#include <QWidget>

class ImgMenuPage:public QWidget
{
    Q_OBJECT
public:
    ImgMenuPage(QWidget *parent=nullptr);
signals:
    void initTable();
    void askMaxCount();
    void searchImg(QString);
    void pageToMain(int);
    void lookUpImg(int,QString);
    void imgClear();
protected:
    void initWidget();
    void initLayout();
    void initConnect();
    void initBackground();
    virtual void resizeEvent(QResizeEvent *event) override;
public slots:
    void chooseDate();
    void setDateSlot();
    void setTable(QStringList name,QStringList cover);
    void search();
    void returnToMain();
    void openImg();
private:
    QLabel *bgLab;
    QLineEdit *searchEdit;
    ImgTable *picTable;
    QPushButton *searchBtn;
    QPushButton *calendarBtn;
    QPushButton *returnBtn;
    QPushButton *selectBtn;
    QCalendarWidget *calendar;
    bool isShow;
};

#endif // IMGMENUPAGE_H
