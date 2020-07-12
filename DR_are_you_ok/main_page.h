#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "bar.h"
#include "video_label.h"
#include "main_page_controller.h"
#include "login_page.h"

#include <QWidget>
#include <QBitmap>
#include <QPainter>

class MainPage:public QWidget
{
    Q_OBJECT
public:
    MainPage(QWidget *parent=nullptr);
signals:
    void askTime();
    void changeToSet(int);
    void sendPic(QImage);
//    void isLogined();
public slots:
    void setDate(QString current);
    void setBarShow();
    void callManager(int index);
    void getPic();
//    void checkLogin();
//    void loginedRet(bool);
protected:
    void initLayout();
    void initWidget();
    void initConnect();
    void initBackground();
    virtual void resizeEvent(QResizeEvent *event) override;
private:
    QLabel *bgLab;
    QLabel *dateLab;
    QPushButton *expandBtn;
    Bar *toolBar;
    VideoLabel *videoLab;
    bool isBarHide;
    LoginPage *login;
};

#endif // MAINPAGE_H
