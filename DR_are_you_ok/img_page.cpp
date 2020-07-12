#include "img_page.h"


ImgPage::ImgPage( QWidget *parent)
    :QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    setFixedSize(600,560);
    setWindowFlags(Qt::FramelessWindowHint);


    //sources="D:/Users/HYJ/Documents/DR_are_you_ok/forImg/2020-07-04-18-35-16.jpg";


    initWidget();
    initLayout();
    initConnect();


}

void ImgPage::setImg(QString name)
{
    emit findImgPath(name);
}



void ImgPage::changeToPrevious()
{
    emit previousImg(sources);
}

void ImgPage::changeToLast()
{
    emit lastImg(sources);
}

void ImgPage::setSources(QString path)
{
    sources=path;
    imgLab->setPixmap(QPixmap(sources).scaled(400,260));
}

void ImgPage::closePage()
{
    emit returnToMenu(3);
    close();
}

void ImgPage::initWidget()
{
    imgLab=new QLabel(this);
    closeBtn=new QPushButton(this);
    previous=new QPushButton(this);
    last=new QPushButton(this);
}

void ImgPage::initConnect()
{
    connect(previous,SIGNAL(clicked(bool)),this,SLOT(changeToPrevious()));
    connect(this,SIGNAL(previousImg(QString)),&ImgPageController::getInstance(),SLOT(getPrevious(QString)));
    connect(&ImgPageController::getInstance(),SIGNAL(setImg(QString)),this,SLOT(setSources(QString)));
    connect(last,SIGNAL(clicked(bool)),this,SLOT(changeToLast()));
    connect(this,SIGNAL(lastImg(QString)),&ImgPageController::getInstance(),SLOT(getLast(QString)));
    connect(this,SIGNAL(findImgPath(QString)),&ImgPageController::getInstance(),SLOT(getImgPath(QString)));
    connect(closeBtn,SIGNAL(clicked(bool)),this,SLOT(closePage()));
}

void ImgPage::initLayout()
{



    //imgLab->setPixmap(QPixmap(sources).scaled(640,360));


    imgLab->setGeometry(100,150,400,260);

    closeBtn->setObjectName("close");
    closeBtn->setGeometry(550,20,30,30);
    closeBtn->setCursor(QCursor(Qt::PointingHandCursor));

    previous->setGeometry(35,265,30,30);
    previous->setIcon(QIcon(QPixmap(":/img/img/previous_img.png")));
    previous->setIconSize(QSize(30,30));
    previous->setCursor(QCursor(Qt::PointingHandCursor));

    last->setGeometry(535,265,30,30);
    last->setIcon(QIcon(QPixmap(":/img/img/last_img.png")));
    last->setIconSize(QSize(30,30));
    last->setCursor(QCursor(Qt::PointingHandCursor));
}

void ImgPage::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(QColor(50, 58, 69, 150));
    p.setBrush(QColor(50, 58, 69, 150));
    //p.setCompositionMode(QPainter::CompositionMode_Clear);
    //p.fillRect(10, 10, 300, 300, Qt::SolidPattern);
    p.drawRect(this->rect());
    QWidget::paintEvent(event);
}

