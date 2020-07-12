#ifndef BAR_H
#define BAR_H

#include <QMenuBar>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QMenuBar>
#include <QPushButton>

class Bar:public QMenuBar
{
    Q_OBJECT
public:
    Bar(int width,QWidget *parent=nullptr);

signals:
    void pageToSetting(int);
    void wantToExit();
    void askPic();
    void pageToPlaybackMenu(int);
    void pageToImgMenu(int);
    void pageToTranscode(int);
//    void isLogined();
public slots:
//    void askLogin();
    void exitSys();
    void toSetting();
    void takePics();
    void playBack();
    void imgOverview();
    void transcode();
protected:
    void initLayout();
    void initWidget();
    void initConnect();
private:
    int width;
    QPushButton *takePicBtn;
    QPushButton *playBackBtn;
    QPushButton *picBtn;
    QPushButton *transcodeBtn;
    QPushButton *setBtn;
    QPushButton *exitBtn;
};

#endif // BAR_H
