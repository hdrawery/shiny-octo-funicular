#ifndef VIDEOLABEL_H
#define VIDEOLABEL_H

#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QMap>
#include <QtMath>
struct Location
{
public:
    explicit Location(float _x,float _y){x=_x;y=_y;}
    float x;
    float y;
};

class VideoLabel:public QLabel
{
     Q_OBJECT
public:
    VideoLabel(int width,int height,QWidget *parent=nullptr);
    void setDotCount(int);
    void setDotColor(const QColor& color);
    void start();
    void setMaxDiameter(float max);
    void setMinDiameter(float min);
    QImage getImg();
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

public slots:
    void receiveImg(QImage img);
    void stop();
private slots:
    void refresh();
private:
    QImage img;
    //刷新计数
    int _index;
    //点的颜色
    QColor _dotColor;
    //点的个数
    int _count;
    //圆点最小直径
    float _minDiameter;
    //圆点最大直径
    float _maxDiameter;
    //绘制圆点
    void paintDot(QPainter & painter);
    //计数
    int _i;
    //时间间隔 单位：毫秒(ms)
    int _interval;
    //定时器
    QTimer timer;
    //绘制区域边长
    float _squareWidth;
    //圆的直径
    float _centerDistance;
    //直径列表
    QList<float> radiiList;
    //圆点坐标列表
    QList<Location> locationList;
    bool isLoading;
    //计算
    void caculate();
    int width;
    int height;
};

#endif // VIDEOLABEL_H
