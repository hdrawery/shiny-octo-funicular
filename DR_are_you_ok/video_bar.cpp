#include "video_bar.h"

#include <QEvent>
#include <QDebug>

int VideoBar::nowPos=0;
VideoBar::VideoBar( int width, QWidget *parent)
    :QMenuBar(parent)
{
    this->width=width;
    setFixedSize(width,75);

    //setStyleSheet("background-color:#323a45;");
    bgLab=new QLabel(this);
    bgLab->setObjectName("bg3");
    bgLab->setScaledContents(true);
    initWidget();
    //videoName->setText(name);
    initLayout();
    initConnect();
    isSpeedDouble=false;
    isStop=true;
}

void VideoBar::setMainIconStop()
{

     mainBtn->setIcon(QIcon(QPixmap(":/img/img/restart.png")));
     mainBtn->setIconSize(QSize(35,35));


}

void VideoBar::setName(QString name)
{
    videoName->setText(name);
}

void VideoBar::setSpeedRestore()
{
    speedBtn->setIcon(QIcon(QPixmap(":/img/img/speed.png")));
    nowPos=0;
}

void VideoBar::initSlider(int len)
{

    speedBtn->setIcon(QIcon(QPixmap(":/img/img/speed.png")));
    nowPos=0;

    videoProgress->setMinimum(0);
    //qDebug()<<"len:"<<len<<endl;
    videoProgress->setMaximum(len-11);
    videoProgress->setSingleStep(1);

}

void VideoBar::valueChanged()
{
    nowPos++;
   // qDebug()<<nowPos<<endl;
    emit value(nowPos);
}

void VideoBar::previousVideo()
{
    emit findPrevious(videoName->text());
}

void VideoBar::lastVideo()
{
    emit findLast(videoName->text());
}

void VideoBar::initInfo(QString name)
{
    videoName->setText(name);
    mainBtn->setIcon(QIcon(QPixmap(":/img/img/stop.png")));
    mainBtn->setIconSize(QSize(35,35));
    emit speed(1);
}

void VideoBar::resizeEvent(QResizeEvent *event)
{
     bgLab->resize(this->size());
}

void VideoBar::stopAndStart()
{
    if(isStop)
    {
        emit restart();
    }
    else
    {
        emit pause();
    }
}

void VideoBar::speedChange()
{
    if(isSpeedDouble)
    {
        emit speed(2);
    }
    else
    {
        emit speed(1);
    }
}

void VideoBar::initWidget()
{
    videoName=new QLabel(this);
    previous=new QPushButton(this);
    last=new QPushButton(this);
    mainBtn=new QPushButton(this);
    speedBtn=new QPushButton(this);
    likeBtn=new QPushButton(this);
    videoProgress=new QSlider(this);
}

void VideoBar::initConnect()
{
    connect(mainBtn,SIGNAL(clicked(bool)),this,SLOT(stopAndStart()));
    connect(speedBtn,SIGNAL(clicked(bool)),this,SLOT(speedChange()));
    connect(this,SIGNAL(value(int)),videoProgress,SLOT(setValue(int)));
    connect(previous,SIGNAL(clicked(bool)),this,SLOT(previousVideo()));
    connect(last,SIGNAL(clicked(bool)),this,SLOT(lastVideo()));
}

bool VideoBar::eventFilter(QObject *watched, QEvent *e)
{
    if(watched==speedBtn)
    {
        if(e->type()==QEvent::MouseButtonPress)
        {
            if(isSpeedDouble)
            {
                speedBtn->setIcon(QIcon(QPixmap(":/img/img/speed.png")));
            }
            else
            {
                speedBtn->setIcon(QIcon(QPixmap(":/img/img/speed_one.png")));
            }
            isSpeedDouble=!isSpeedDouble;
        }

    }
    else if(watched==mainBtn)
    {
        if(e->type()==QEvent::MouseButtonPress)
        {
            if(isStop)
            {
                mainBtn->setIcon(QIcon(QPixmap(":/img/img/restart.png")));

            }
            else
            {
                mainBtn->setIcon(QIcon(QPixmap(":/img/img/stop.png")));

            }
            mainBtn->setIconSize(QSize(35,35));
            isStop=!isStop;
        }
    }
    else if(watched==likeBtn)
    {
        if(e->type()==QEvent::MouseButtonPress)
        {
            likeBtn->setIcon(QIcon(QPixmap(":/img/img/like_onclick.png")));
            likeBtn->setIconSize(QSize(25,25));
        }

    }
    return QWidget::eventFilter(watched,e);
}
void VideoBar::initLayout()
{
    videoProgress->setGeometry(0,0,width,5);
    videoProgress->setObjectName("videoProgress");
    videoProgress->setOrientation(Qt::Horizontal);

    videoName->setStyleSheet("font-family:Comic Sans MS;color:white;");
    videoName->setGeometry(30,25,200,30);

    previous->setObjectName("previous");
    previous->setGeometry(330,27,25,25);

    previous->setCursor(QCursor(Qt::PointingHandCursor));

    mainBtn->setObjectName("labBtn");
    mainBtn->setGeometry(375,22,35,35);
    mainBtn->setIcon(QIcon(QPixmap(":/img/img/stop.png")));
    mainBtn->setIconSize(QSize(35,35));
    mainBtn->installEventFilter(this);
    mainBtn->setCursor(QCursor(Qt::PointingHandCursor));

    last->setObjectName("last");
    last->setGeometry(430,27,25,25);
    last->setCursor(QCursor(Qt::PointingHandCursor));

    speedBtn->setObjectName("labBtn");
    speedBtn->setGeometry(695,30,25,25);
    speedBtn->setIcon(QIcon(QPixmap(":/img/img/speed.png")));
    speedBtn->setIconSize(QSize(20,20));
    speedBtn->setCursor(QCursor(Qt::PointingHandCursor));
    speedBtn->installEventFilter(this);

    likeBtn->setObjectName("labBtn");
    likeBtn->setGeometry(740,28,25,25);
    likeBtn->setIcon(QIcon(QPixmap(":/img/img/like.png")));
    likeBtn->setIconSize(QSize(25,25));
    likeBtn->setCursor(QCursor(Qt::PointingHandCursor));
    likeBtn->installEventFilter(this);

}
