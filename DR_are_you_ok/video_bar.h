#ifndef VIDEOBAR_H
#define VIDEOBAR_H

#include <QLabel>
#include <QMenuBar>
#include <QPushButton>
#include <QSlider>



class VideoBar:public QMenuBar
{
    Q_OBJECT
public:
    VideoBar(int width,QWidget *parent=nullptr);
    void setMainIconStop();
    void setName(QString name);
signals:
    void pause();
    void restart();
    void speed(int);
    void value(int);
    void findPrevious(QString);
    void findLast(QString);
public slots:
    void stopAndStart();
    void speedChange();
    void setSpeedRestore();
    void initSlider(int len);
    void valueChanged();
    void previousVideo();
    void lastVideo();
    void initInfo(QString name);
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    void initLayout();
    void initWidget();
    void initConnect();
    virtual bool eventFilter(QObject *watched, QEvent *e) override;
private:
    int width;
    QLabel *videoName;
    QPushButton *previous;
    QPushButton *last;
    QPushButton *mainBtn;
    QPushButton *speedBtn;
    QPushButton *likeBtn;
    QSlider *videoProgress;
    bool isSpeedDouble;
    bool isStop;
    static int nowPos;
    bool isSwitch;
    QLabel *bgLab;
};

#endif // VIDEOBAR_H
