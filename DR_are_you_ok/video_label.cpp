#include "video_label.h"




VideoLabel::VideoLabel(int width, int height, QWidget *parent)
     :QLabel(parent),_i(0),_interval(20),_index(0)
{
    this->width=width;
    this->height=height;

    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    setObjectName("video");
    shadow_effect->setOffset(0, 5);
    shadow_effect->setColor(QColor(43, 43, 43));
    shadow_effect->setBlurRadius(20);

    setGraphicsEffect(shadow_effect);

    setDotColor(QColor(255, 255, 255));
    setDotCount(20);
    connect(&timer,&QTimer::timeout,this,&VideoLabel::refresh);
    setMaxDiameter(30);
    setMinDiameter(5);
    start();
    //connect(this,SIGNAL(stopLoading),this,SLOT(stop()));
    isLoading=true;
}

void VideoLabel::paintEvent(QPaintEvent *event)
{

    if(!img.isNull())
    {
        QPainter painter(this);
        painter.drawImage(QRect(0,0,width,height),img);
    }
    else if(isLoading)
    {
        Q_UNUSED(event)
        QPainter painter(this);

        painter.setRenderHint(QPainter::Antialiasing);

        painter.setPen(_dotColor);
        painter.setBrush(_dotColor);

        //绘制点
        paintDot(painter);
    }
}

void VideoLabel::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    caculate();
}

void VideoLabel::stop()
{
    timer.stop();
}
void VideoLabel::setDotCount(int count)
{
    _count=count;
}

void VideoLabel::setDotColor(const QColor &color)
{
    _dotColor=color;
}

void VideoLabel::start()
{
    timer.setInterval(_interval);
    timer.start();
}

void VideoLabel::setMaxDiameter(float max)
{
    _maxDiameter=max;
}

void VideoLabel::setMinDiameter(float min)
{
     _minDiameter=min;
}

void VideoLabel::refresh()
{
    repaint();
}

void VideoLabel::paintDot(QPainter & painter)
{
    for(int i=0;i<_count;i++)
    {
        painter.setPen(_dotColor);
        //半径
        float radii=radiiList.at((_index+_count-i)%_count);

        //绘制圆点
        painter.drawEllipse(QPointF(120+locationList.at(i).x,locationList.at(i).y),radii,radii);
    }
    _index++;
}

void VideoLabel::caculate()
{
    _squareWidth=qMin(this->width,this->height);
    float half=_squareWidth/2;
    _centerDistance=half-_maxDiameter/2-1;

    float gap=(_maxDiameter-_minDiameter)/(_count-1)/2;
    float angleGap=(float)360/_count;

    locationList.clear();
    radiiList.clear();

    for(int i=0;i<_count;i++)
    {
        radiiList<<_maxDiameter/2-i*gap;
        float radian=qDegreesToRadians(-angleGap*i);
        locationList.append(Location(half+_centerDistance*qCos(radian),half-_centerDistance*qSin(radian)));
    }
}
void VideoLabel::receiveImg(QImage img)
{
    //qDebug()<<"receive"<<endl;
    isLoading=false;
    timer.stop();
    this->img=img;
    this->update();
}
QImage VideoLabel::getImg()
{
    return img;
}
