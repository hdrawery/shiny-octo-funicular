#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include "img_menu_page.h"
#include "img_page.h"
#include "login_page.h"
#include "main_page.h"
#include "play_page.h"
#include "playback_menu_page.h"
#include "register_page.h"
#include "set_page.h"
#include "transcode_page.h"


#include <QStackedWidget>
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QApplication>
#include <QVBoxLayout>

class WidgetManager:public QWidget
{
    Q_OBJECT
public:
    WidgetManager();
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    void initconnect();
    void initPage();
signals:
    void isNeedInitCam();//询问是否需要初始化，需要则进入setPage
    void changePage();
    void startCamera();
    void restartCamera();
    void initTable();
    void initImgTable();
    void initListWidget();
    void findNewId();
public slots:
    void changePage(int index);
    void setFirstPage(bool isNull);
    void ImgShow(int index,QString name);
    void VideoPlay(int index,QString name);
private:
    PlaybackMenuPage *playbackMenu;
    MainPage *mainPage;
    SetPage *setPage;
    bool bPressFlag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPOint;
    QStackedWidget *stack;
    ImgMenuPage *imgMenu;
    ImgPage *imgPage;
    PlayPage *playPage;
    TranscodePage *transcodePage;
    RegisterPage *registPage;
};

#endif // WIDGETMANAGER_H
