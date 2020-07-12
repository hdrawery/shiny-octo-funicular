#include "main_page.h"


MainPage::MainPage(QWidget *parent)
    :QWidget(parent)
{
    setFixedSize(800,600);
    initBackground();


    isBarHide=true;

    initWidget();
    initLayout();
    initConnect();
    emit askTime();
}
void MainPage::setDate(QString current)
{

    dateLab->setText(current);

}

void MainPage::setBarShow()
{
    if(isBarHide)
    {
        toolBar->show();
        expandBtn->setIcon(QIcon(QPixmap(":/img/img/barHide.png")));
    }
    else
    {
        toolBar->hide();
        expandBtn->setIcon(QIcon(QPixmap(":/img/img/barShow.png")));
    }
    isBarHide=!isBarHide;
}

void MainPage::callManager(int index)
{
    if(index==7)
    {
        emit changeToSet(index);
        return;
    }
    bool ret=UserController::getInstance().getIsLogined();
    if(ret)
    {
        emit changeToSet(index);
    }
    else
    {

        login->exec();
    }
}



void MainPage::getPic()
{
    QImage img=videoLab->getImg();
    emit sendPic(img);
}

//void MainPage::checkLogin()
//{
//    emit isLogined();
//}





void MainPage::initLayout()
{
    toolBar->hide();
    dateLab->setObjectName("barLab");
    expandBtn->setObjectName("barBtn_styleThree");
    expandBtn->setIcon(QIcon(QPixmap(":/img/img/barShow.png")));
    expandBtn->setCursor(QCursor(Qt::PointingHandCursor));
    expandBtn->setIconSize(QSize(24,24));
    expandBtn->setGeometry(725,0,75,75);
    dateLab->setGeometry(320,1,200,75);
    toolBar->setGeometry(725,76,75,450);
    videoLab->setGeometry(35,100,720,455);
    toolBar->raise();
}

void MainPage::initWidget()
{
    dateLab=new QLabel(this);
    expandBtn=new QPushButton(this);
    toolBar=new Bar(75,this);
    videoLab=new VideoLabel(720,455,this);
    login=new LoginPage(this);
}

void MainPage::initConnect()
{
    connect(expandBtn,SIGNAL(clicked(bool)),this,SLOT(setBarShow()));
    connect(this,SIGNAL(askTime()),&MainPageController::getInstance(),SLOT(getTime()));
    connect(&MainPageController::getInstance(),SIGNAL(findCurrentDate(QString)),this,SLOT(setDate(QString)));
    connect(toolBar,SIGNAL(pageToSetting(int)),this,SLOT(callManager(int)));
    connect(toolBar,SIGNAL(wantToExit()),&MainPageController::getInstance(),SLOT(exitSys()));

    connect(&MainPageController::getInstance(),SIGNAL(sendImg(QImage)),videoLab,SLOT(receiveImg(QImage)));
    connect(toolBar,SIGNAL(askPic()),this,SLOT(getPic()));
    connect(toolBar,SIGNAL(pageToPlaybackMenu(int)),this,SLOT(callManager(int)));
    connect(toolBar,SIGNAL(pageToImgMenu(int)),this,SLOT(callManager(int)));

    connect(this,SIGNAL(sendPic(QImage)),&MainPageController::getInstance(),SLOT(saveImg(QImage)));
    connect(toolBar,SIGNAL(pageToTranscode(int)),this,SLOT(callManager(int)));
    connect(login,SIGNAL(pageToRegister(int)),this,SLOT(callManager(int)));

}

void MainPage::initBackground()
{
    QBitmap bmp(800,600);
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),5,5);
    setMask(bmp);

    bgLab=new QLabel(this);
    bgLab->setPixmap(QPixmap(":/img/img/main_bg.jpg"));
    bgLab->setScaledContents(true);
}

void MainPage::resizeEvent(QResizeEvent *event)
{
    bgLab->resize(this->size());
}
