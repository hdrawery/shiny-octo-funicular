#include "set_page.h"

SetPage::SetPage(QWidget *parent)
    :QWidget(parent)
{
    setFixedSize(550,600);

    bgLab=new QLabel(this);
    bgLab->setObjectName("bg");
    bgLab->setScaledContents(true);

    QBitmap bmp(550,600);
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),5,5);
    setMask(bmp);

    initWidget();
    initLayout();
    initConnect();
    emit askCamName();
}
void SetPage::setCamName(QString name)
{
    camName->setText(name);
    emit askCamInfo();
}
void SetPage::applySet()
{
    if(videoSavePath->text()==""||imgSavePath->text()==""||timeInterval->text()=="")
    {
        //以后可以改弹窗显示不能为空
        return ;
    }
    emit applyCamSet(videoSavePath->text(),imgSavePath->text(),timeInterval->text(),camName->text());
    emit finishCamSet(0);
}

void SetPage::initSetPage(QString video, QString img, QString interval)
{
    if(video==""||img==""||interval=="")
    {
        return;
    }
    videoSavePath->setText(video);
    imgSavePath->setText(img);
    timeInterval->setText(interval);
}

void SetPage::cancelSet()
{
    if(videoSavePath->text()==""||imgSavePath->text()==""||timeInterval->text()=="")
    {
        //以后可以改弹窗显示不能为空
        return ;
    }
    emit finishCamSet(0);
}
void SetPage::initWidget()
{
    QPixmap *pix1=new QPixmap(":/img/img/videoSave.jpg");
    videoSavePath=new LineEdit(pix1,PATH,this);
    QPixmap *pix2=new QPixmap(":/img/img/imgSave.jpg");
    imgSavePath=new LineEdit(pix2,PATH,this);
    QPixmap *pix3=new QPixmap(":/img/img/timeInterval.jpg");
    timeInterval=new LineEdit(pix3,COMMON,this);
    QPixmap *pix4=new QPixmap(":/img/img/camName.jpg");
    camName=new LineEdit(pix4,COMMON,this);
    cancelBtn=new QPushButton("cancel",this);
    okBtn=new QPushButton("apply",this);
    tips=new QLabel("*frame",this);
}
void SetPage::initLayout()
{

    cancelBtn->setObjectName("styleTwo");
    okBtn->setObjectName("styleOne");

    cancelBtn->setGeometry(0,540,275,60);
    cancelBtn->setCursor(QCursor(Qt::PointingHandCursor));
    okBtn->setGeometry(275,540,275,60);
    okBtn->setCursor(QCursor(Qt::PointingHandCursor));

    tips->setStyleSheet("font-family:Lucida Console;color:#9fa7b4;");

    videoSavePath->setGeometry(102,110,345,55);
    imgSavePath->setGeometry(102,200,345,55);
    timeInterval->setGeometry(102,290,345,55);
    tips->setGeometry(455,300,60,30);
    camName->setGeometry(102,380,345,55);

    videoSavePath->setPlaceholderText("Video Save Path");
    imgSavePath->setPlaceholderText("Image Save Path");
    timeInterval->setPlaceholderText("Time Interval");


    camName->setReadOnly(true);

    QRegExpValidator *pattern= new QRegExpValidator(QRegExp("^[0-9]*[1-9][0-9]*$"), this);
    timeInterval->setValidator(pattern);
}
void SetPage::initConnect()
{
    connect(this,SIGNAL(askCamName()),&SetPageController::getInstance(),SLOT(getCamName()));
    connect(&SetPageController::getInstance(),SIGNAL(findCamName(QString)),this,SLOT(setCamName(QString)));
    connect(okBtn,SIGNAL(clicked(bool)),this,SLOT(applySet()));
    connect(this,SIGNAL(applyCamSet(QString,QString,QString,QString)),&SetPageController::getInstance(),SLOT(setCam(QString,QString,QString,QString)));
    connect(this,SIGNAL(askCamInfo()),&SetPageController::getInstance(),SLOT(getCamInfo()));
    connect(&SetPageController::getInstance(),SIGNAL(findCamInfo(QString,QString,QString)),this,SLOT(initSetPage(QString,QString,QString)));
    connect(cancelBtn,SIGNAL(clicked(bool)),this,SLOT(cancelSet()));
}

void SetPage::resizeEvent(QResizeEvent *event)
{
    bgLab->resize(this->size());
}
