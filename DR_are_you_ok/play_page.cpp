#include "play_page.h"


#include <QBitmap>
#include <QPainter>


PlayPage::PlayPage(QWidget *parent)
    :QWidget(parent)
{
    setFixedSize(798,600);
    setWindowFlags(Qt::FramelessWindowHint);
    bgLab=new QLabel(this);
    bgLab->setObjectName("bg2");
    bgLab->setScaledContents(true);
    initBackground();



    initWidget();
    initLayout();
    initConnect();



}

void PlayPage::setSources(QString name)
{
    sources=name;
    videoBar->setName(name);
    emit openSources(sources);
}

void PlayPage::initWidget()
{
    returnBtn=new QPushButton(this);
    exportBtn=new QPushButton(this);
    screenshotBtn=new QPushButton(this);
    videoBar=new VideoBar(798,this);
    videoLab=new VideoLabel(798,350,this);
}

void PlayPage::initLayout()
{
    returnBtn->setObjectName("styleTwo");
    exportBtn->setObjectName("styleOne");
    screenshotBtn->setObjectName("styleThree");
    returnBtn->setGeometry(0,0,266,60);
    exportBtn->setGeometry(266,0,266,60);
    screenshotBtn->setGeometry(532,0,266,60);
    returnBtn->setCursor(QCursor(Qt::PointingHandCursor));
    exportBtn->setCursor(QCursor(Qt::PointingHandCursor));
    screenshotBtn->setCursor(QCursor(Qt::PointingHandCursor));

    returnBtn->setIcon(QIcon(QPixmap(":/img/img/returnMenu.png")));
    returnBtn->setIconSize(QSize(28,28));
    exportBtn->setIcon(QIcon(QPixmap(":/img/img/export.png")));
    exportBtn->setIconSize(QSize(28,28));
    screenshotBtn->setIcon(QIcon(QPixmap(":/img/img/screenshot.png")));
    screenshotBtn->setIconSize(QSize(28,28));

    videoBar->setGeometry(0,525,798,75);


    videoLab->setGeometry(0,120,798,350);

}

void PlayPage::initConnect()
{
    connect(&PlayPageController::getInstance(),SIGNAL(sendImg(QImage)),videoLab,SLOT(receiveImg(QImage)));
    connect(&PlayPageController::getInstance(),SIGNAL(sendImg(QImage)),videoBar,SLOT(valueChanged()));
    connect(this,SIGNAL(openSources(QString)),&PlayPageController::getInstance(),SLOT(setSources(QString)));
    connect(videoBar,SIGNAL(pause()),&PlayPageController::getInstance(),SLOT(pause()));
    connect(videoBar,SIGNAL(restart()),&PlayPageController::getInstance(),SLOT(restart()));
    connect(videoBar,SIGNAL(speed(int)),&PlayPageController::getInstance(),SLOT(changeSpeed(int)));
    connect(&PlayPageController::getInstance(),SIGNAL(finished()),this,SLOT(setIconStop()));
    connect(&PlayPageController::getInstance(),SIGNAL(replay()),videoBar,SLOT(setSpeedRestore()));
    connect(&PlayPageController::getInstance(),SIGNAL(videoSize(int)),videoBar,SLOT(initSlider(int)));
    connect(&PlayPageController::getInstance(),SIGNAL(videoInit(QString)),videoBar,SLOT(initInfo(QString)));
    connect(screenshotBtn,SIGNAL(clicked(bool)),this,SLOT(sendSaveScreenShot()));
    connect(this,SIGNAL(sendSaveImg(QImage)),&PlayPageController::getInstance(),SLOT(saveImg(QImage)));

    connect(videoBar,SIGNAL(findPrevious(QString)),&PlayPageController::getInstance(),SLOT(findPrevious(QString)));
    connect(videoBar,SIGNAL(findLast(QString)),&PlayPageController::getInstance(),SLOT(findLast(QString)));
    connect(exportBtn,SIGNAL(clicked(bool)),this,SLOT(transcode()));
    connect(this,SIGNAL(transcodeSources(QString)),&PlayPageController::getInstance(),SLOT(transcode()));
    connect(returnBtn,SIGNAL(clicked(bool)),this,SLOT(closePage()));
}

void PlayPage::initBackground()
{
    QBitmap bmp(798,600);
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),5,5);
    setMask(bmp);
}

void PlayPage::setIconStop()
{
    videoBar->setMainIconStop();
}

void PlayPage::sendSaveScreenShot()
{
    QImage img=videoLab->getImg();
    emit sendSaveImg(img);
}

void PlayPage::transcode()
{
    if(sources!="")
    {
        emit transcodeSources(sources);
    }

}

void PlayPage::closePage()
{
    emit returnToMenu(2);
    close();
}



void PlayPage::resizeEvent(QResizeEvent *event)
{
    bgLab->resize(this->size());
}
