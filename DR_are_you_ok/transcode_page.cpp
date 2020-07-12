#include "transcode_page.h"

#include <QBitmap>
#include <QFileDialog>
#include <QGraphicsDropShadowEffect>
#include <QPainter>



TranscodePage::TranscodePage(QWidget *parent)
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

    //emit initListWidget();
}

void TranscodePage::initWidget()
{
    calendarBtn=new QPushButton(this);
    searchEdit=new QLineEdit(this);
    calendar=new QCalendarWidget(this);
    searchBtn=new QPushButton(this);
    returnBtn=new QPushButton("return",this);
    okBtn=new QPushButton("apply",this);
    imgList=new VideoListWidget(800,this);
    progressBar=new QProgressBar(this);

    formatLab=new QLabel("transcode format",this);
    formatCombo=new QComboBox(this);

    savePathLab=new QLabel("save path",this);
    fileEdit=new QLineEdit(this);

    fileBtn=new QPushButton(this);
}

void TranscodePage::initLayout()
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



    returnBtn->setObjectName("styleTwo");
    okBtn->setObjectName("styleOne");

    returnBtn->setGeometry(0,540,400,60);
    returnBtn->setCursor(QCursor(Qt::PointingHandCursor));
    okBtn->setGeometry(400,540,400,60);
    okBtn->setCursor(QCursor(Qt::PointingHandCursor));



    calendar->setGraphicsEffect(shadow_effect);
    calendar->setHidden(true);

    imgList->setGeometry(0,70,800,270);
    progressBar->setGeometry(0,340,800,25);
    progressBar->setOrientation(Qt::Horizontal);
    //progressBar->setTextVisible(false);



    formatLab->setObjectName("transcode");
    formatLab->setContentsMargins(18,0,0,0);

    formatCombo->setView(new QListView);
    QStringList formatList;
    formatList<<"MP4";
    formatList<<"AVI";
    formatList<<"MOV";
    formatCombo->addItems(formatList);

    formatLab->setGeometry(50,425,145,40);
    formatCombo->setGeometry(190,425,140,40);

    savePathLab->setObjectName("transcode");
    savePathLab->setContentsMargins(18,0,0,0);
    savePathLab->setGeometry(380,425,100,40);
    fileEdit->setObjectName("transcode");
    fileEdit->setGeometry(480,425,270,40);

    fileBtn->setObjectName("transcode_file");

    fileBtn->setGeometry(722,437,16,16);
    fileBtn->setCursor(QCursor(Qt::PointingHandCursor));

}

void TranscodePage::initConnect()
{
    connect(calendarBtn,SIGNAL(clicked(bool)),this,SLOT(chooseDate()));
    connect(calendar,SIGNAL(clicked(QDate)),this,SLOT(setDateSlot()));
    connect(fileBtn,SIGNAL(clicked(bool)),this,SLOT(setPath()));

    connect(this,SIGNAL(initListWidget()),&TranscodePageController::getInstance(),SLOT(getVideoInfo()));
    connect(&TranscodePageController::getInstance(),SIGNAL(videoOverview(QStringList,QStringList)),this,SLOT(setListWidget(QStringList,QStringList)));


    connect(imgList,SIGNAL(findNext()),&TranscodePageController::getInstance(),SLOT(nextVideo()));
    connect(imgList,SIGNAL(findPrevious()),&TranscodePageController::getInstance(),SLOT(previousVideo()));
    connect(searchBtn,SIGNAL(clicked(bool)),this,SLOT(search()));
    connect(this,SIGNAL(searchVideo(QString)),&TranscodePageController::getInstance(),SLOT(setVideoDate(QString)));

    connect(okBtn,SIGNAL(clicked(bool)),this,SLOT(toTranscode()));
    connect(this,SIGNAL(transcode(QString,QString,QString)),&TranscodePageController::getInstance(),SLOT(transcodeThread(QString,QString,QString)));
    connect(&TranscodePageController::getInstance(),SIGNAL(videoSize(int)),this,SLOT(initProgress(int)));
    connect(&TranscodePageController::getInstance(),SIGNAL(sendCount(int)),progressBar,SLOT(setValue(int)));
    connect(returnBtn,SIGNAL(clicked(bool)),this,SLOT(returnToMain()));

    connect(this,SIGNAL(videoClear()),&TranscodePageController::getInstance(),SLOT(clearVideo()));
}

void TranscodePage::initBackground()
{
    QBitmap bmp(800,600);
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),5,5);
    setMask(bmp);

    bgLab=new QLabel(this);
    bgLab->setPixmap(QPixmap(":/img/img/transcode_bg.jpg"));
    bgLab->setScaledContents(true);
    isShow=false;
}

void TranscodePage::resizeEvent(QResizeEvent *event)
{
    bgLab->resize(this->size());
}

void TranscodePage::returnToMain()
{
    emit pageToMain(0);
    emit videoClear();
}

void TranscodePage::initProgress(int max)
{
    qDebug()<<"max:"<<max<<endl;
    progressBar->setMaximum(max);
    progressBar->setValue(0);
}

void TranscodePage::chooseDate()
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

void TranscodePage::setDateSlot()
{
    QDate date = calendar->selectedDate();
    searchEdit->setText(date.toString("yyyy-MM-dd"));
}

void TranscodePage::setPath()
{
    QString path=QFileDialog::getExistingDirectory(this,"Open Directory","/",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);

    fileEdit->setText(path);
}

void TranscodePage::setListWidget(QStringList name,QStringList cover)
{

    imgList->clearList();
    imgList->setNameList(name);
    for(int i=0;i<cover.size();i++)
    {
       // qDebug()<<cover[i]<<endl;
        imgList->initListWidget(cover[i]);
    }
}

void TranscodePage::search()
{
    if(searchEdit->text()=="")
    {
        emit initListWidget();
    }
    else
    {
        emit searchVideo(searchEdit->text());
        //qDebug()<<"click"<<endl;
    }
}

void TranscodePage::toTranscode()
{
    QString name=imgList->getSelectedName();
    qDebug()<<name<<endl;
    QString path=fileEdit->text()+'/'+name;
    QString format=formatCombo->currentText().toLower();
    emit transcode(name,path,format);

}
