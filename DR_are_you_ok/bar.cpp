#include "bar.h"

Bar::Bar(int width,QWidget *parent)
    :QMenuBar(parent)
{
    this->width=width;
    setFixedSize(width,width*6+2);
    setWindowFlags(Qt::FramelessWindowHint);
    //setAttribute(Qt::WA_TranslucentBackground);
    //setWindowOpacity(0);
    //setStyleSheet("background:rgba(255, 255, 255, 100);");

    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 5);
    shadow_effect->setColor(QColor(60, 60, 60));
    shadow_effect->setBlurRadius(20);

    setGraphicsEffect(shadow_effect);

    initWidget();
    initLayout();
    initConnect();
}

//void Bar::askLogin()
//{
//    emit isLogined();
//}

void Bar::exitSys()
{
    emit wantToExit();
}

void Bar::toSetting()
{
    emit pageToSetting(1);
}

void Bar::takePics()
{
    emit askPic();
}

void Bar::playBack()
{
    emit pageToPlaybackMenu(2);
}

void Bar::imgOverview()
{
    emit pageToImgMenu(3);
}

void Bar::transcode()
{
    emit pageToTranscode(6);
}



void Bar::initLayout()
{
    QVBoxLayout* pLayout = new QVBoxLayout(this);

    pLayout->setSpacing(1);
    pLayout->setMargin(0);

    takePicBtn->setObjectName("barBtn_styleOne");
    takePicBtn->setIcon(QIcon(QPixmap(":/img/img/takePic.png")));
    takePicBtn->setIconSize(QSize(32,32));
    takePicBtn->setCursor(QCursor(Qt::PointingHandCursor));
    takePicBtn->setToolTip("take a picture");
    pLayout->addWidget(takePicBtn);

    playBackBtn->setObjectName("barBtn_styleTwo");
    playBackBtn->setIcon(QIcon(QPixmap(":/img/img/playBack.png")));
    playBackBtn->setIconSize(QSize(32,32));
    playBackBtn->setCursor(QCursor(Qt::PointingHandCursor));
    playBackBtn->setToolTip("video playback");
    pLayout->addWidget(playBackBtn);

    picBtn->setObjectName("barBtn_styleThree");
    picBtn->setIcon(QIcon(QPixmap(":/img/img/pics.png")));
    picBtn->setIconSize(QSize(32,32));
    picBtn->setCursor(QCursor(Qt::PointingHandCursor));
    picBtn->setToolTip("picture preview");
    pLayout->addWidget(picBtn);

    transcodeBtn->setObjectName("barBtn_styleOne");
    transcodeBtn->setIcon(QIcon(QPixmap(":/img/img/transCode.png")));
    transcodeBtn->setIconSize(QSize(32,32));
    transcodeBtn->setCursor(QCursor(Qt::PointingHandCursor));
    transcodeBtn->setToolTip("video transcoding");
    pLayout->addWidget(transcodeBtn);

    setBtn->setObjectName("barBtn_styleTwo");
    setBtn->setIcon(QIcon(QPixmap(":/img/img/set.png")));
    setBtn->setIconSize(QSize(32,32));
    setBtn->setCursor(QCursor(Qt::PointingHandCursor));
    setBtn->setToolTip("system settings");
    pLayout->addWidget(setBtn);

    exitBtn->setObjectName("barBtn_styleThree");
    exitBtn->setIcon(QIcon(QPixmap(":/img/img/exit.png")));
    exitBtn->setIconSize(QSize(32,32));
    exitBtn->setCursor(QCursor(Qt::PointingHandCursor));
    exitBtn->setToolTip("exit system");
    pLayout->addWidget(exitBtn);

    setLayout(pLayout);
}
void Bar::initWidget()
{
    takePicBtn=new QPushButton(this);
    takePicBtn->setFixedSize(width,width);
    playBackBtn=new QPushButton(this);
    playBackBtn->setFixedSize(width,width);
    picBtn=new QPushButton(this);
    picBtn->setFixedSize(width,width);
    transcodeBtn=new QPushButton(this);
    transcodeBtn->setFixedSize(width,width);
    setBtn=new QPushButton(this);
    setBtn->setFixedSize(width,width);
    exitBtn=new QPushButton(this);
    exitBtn->setFixedSize(width,width);
}

void Bar::initConnect()
{
    connect(exitBtn,SIGNAL(clicked(bool)),this,SLOT(exitSys()));
    connect(setBtn,SIGNAL(clicked(bool)),this,SLOT(toSetting()));
//    //之后要改成先登录检测
//    connect(takePicBtn,SIGNAL(clicked(bool)),this,SLOT(askLogin()));
    connect(takePicBtn,SIGNAL(clicked(bool)),this,SLOT(takePics()));
    connect(playBackBtn,SIGNAL(clicked(bool)),this,SLOT(playBack()));
    connect(picBtn,SIGNAL(clicked(bool)),this,SLOT(imgOverview()));
    connect(transcodeBtn,SIGNAL(clicked(bool)),this,SLOT(transcode()));
}
