#ifndef PLAYBACKMENUPAGE_H
#define PLAYBACKMENUPAGE_H

#include "img_table.h"
#include "line_edit.h"
#include "menu_controller.h"

#include <QTableWidget>
#include <QWidget>
#include <QCalendarWidget>

#include <QBitmap>
#include <QPainter>
class PlaybackMenuPage:public QWidget
{
    Q_OBJECT
public:
    PlaybackMenuPage(QWidget *parent=nullptr);

signals:
    void initTable();
    void askMaxCount();
    void searchVideo(QString);
    void pageToMain(int);
    void videoPlay(int ,QString);

    void videoClear();
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
    void openSources();
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

#endif // PLAYBACKMENUPAGE_H
