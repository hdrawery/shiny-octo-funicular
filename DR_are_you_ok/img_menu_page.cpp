#include "img_menu_page.h"
#include "menu_controller.h"

#include <QBitmap>
#include <QGraphicsDropShadowEffect>
#include <QLineEdit>
#include <QPainter>






ImgMenuPage::ImgMenuPage(QWidget *parent)
    :QWidget(parent)
{
    setFixedSize(800,600);
    setWindowFlags(Qt::FramelessWindowHint);
    bgLab=new QLabel(this);
    bgLab->setObjectName("bg");
    bgLab->setScaledContents(true);
    initBackground();
    initWidget();
    initLayout();
    initConnect();
    //emit initTable();
    //emit askMaxCount();

}
void ImgMenuPage::initWidget()
{
    calendarBtn=new QPushButton(this);
    searchEdit=new QLineEdit(this);
    calendar=new QCalendarWidget(this);
    searchBtn=new QPushButton(this);
    returnBtn=new QPushButton("return",this);
    selectBtn=new QPushButton("select",this);
    picTable=new ImgTable(this);
}

void ImgMenuPage::initLayout()
{
    calendarBtn->setObjectName("calendar");
    calendarBtn->setGeometry(40,20,30,30);
    calendarBtn->setCursor(QCursor(Qt::PointingHandCursor));

    searchEdit->setObjectName("search");
    //searchEdit->setReadOnly(true);
    searchEdit->setGeometry(100,13,330,45);

    searchBtn->setObjectName("search");
    searchBtn->setCursor(QCursor(Qt::PointingHandCursor));
    searchBtn->setGeometry(385,20,30,30);

    calendar->setGeometry(1,70,400,400);
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 5);
    shadow_effect->setColor(QColor(60, 60, 60));
    shadow_effect->setBlurRadius(20);

    picTable->setGeometry(10,90,780,435);


    returnBtn->setObjectName("styleTwo");
    selectBtn->setObjectName("styleOne");

    returnBtn->setGeometry(0,540,400,60);
    returnBtn->setCursor(QCursor(Qt::PointingHandCursor));
    selectBtn->setGeometry(400,540,400,60);
    selectBtn->setCursor(QCursor(Qt::PointingHandCursor));



    calendar->setGraphicsEffect(shadow_effect);
    calendar->setHidden(true);
}

void ImgMenuPage::initConnect()
{
    connect(calendarBtn,SIGNAL(clicked(bool)),this,SLOT(chooseDate()));
    connect(calendar,SIGNAL(clicked(QDate)),this,SLOT(setDateSlot()));
    connect(this,SIGNAL(initTable()),&MenuController::getInstance(),SLOT(getImgInfo()));
    connect(&MenuController::getInstance(),SIGNAL(imgOverview(QStringList,QStringList)),this,SLOT(setTable(QStringList,QStringList)));
    connect(picTable,SIGNAL(previous()),&MenuController::getInstance(),SLOT(previousImg()));
    connect(picTable,SIGNAL(next()),&MenuController::getInstance(),SLOT(nextImg()));
    connect(this,SIGNAL(askMaxCount()),&MenuController::getInstance(),SLOT(getVideoMaxCount()));
    connect(&MenuController::getInstance(),SIGNAL(sendImgSum(int)),picTable,SLOT(setScrollLength(int)));
    connect(searchBtn,SIGNAL(clicked(bool)),this,SLOT(search()));
    connect(this,SIGNAL(searchImg(QString)),&MenuController::getInstance(),SLOT(setImgDate(QString)));
    connect(returnBtn,SIGNAL(clicked(bool)),this,SLOT(returnToMain()));
    connect(selectBtn,SIGNAL(clicked(bool)),this,SLOT(openImg()));
    connect(this,SIGNAL(imgClear()),&MenuController::getInstance(),SLOT(clearImg()));
}
void ImgMenuPage::initBackground()
{
    QBitmap bmp(800,600);
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),5,5);
    setMask(bmp);

    bgLab=new QLabel(this);
    bgLab->setPixmap(QPixmap(":/img/img/playback_bg.jpg"));
    bgLab->setScaledContents(true);
    isShow=false;


}
void ImgMenuPage::resizeEvent(QResizeEvent *event)
{
    bgLab->resize(this->size());
}



void ImgMenuPage::chooseDate()
{
    if(!isShow)
    {
        calendar->setHidden(false);
        calendar->raise();
    }
    else
    {
        calendar->setHidden(true);
    }
    isShow=!isShow;
}

void ImgMenuPage::setDateSlot()
{
    QDate date = calendar->selectedDate();
    searchEdit->setText(date.toString("yyyy-MM-dd"));

}

void ImgMenuPage::setTable(QStringList name, QStringList cover)
{
    if(name.size()!=cover.size()||name.size()==0||cover.size()==0)
    {
        return;
    }
    else
    {
        picTable->clear();
    }
    int i;
    int x=0,y=0;
    for(i=0;i<name.size();i++)
    {
        if(y==3)
        {
            y=0;
            x++;
        }
        picTable->setImgMap(name[i],cover[i],x,y);
        y++;
    }


}

void ImgMenuPage::search()
{
    if(searchEdit->text()=="")
    {
        emit initTable();
    }
    else
    {
        emit searchImg(searchEdit->text());
        //qDebug()<<"click"<<endl;
    }
}

void ImgMenuPage::returnToMain()
{
    emit pageToMain(0);
    emit imgClear();
}

void ImgMenuPage::openImg()
{
    QString name=picTable->getImgName();
    picTable->resetImgName();
    if(name!="")
    {
        emit lookUpImg(4,name);
    }

}
