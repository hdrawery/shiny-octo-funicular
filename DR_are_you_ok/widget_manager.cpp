
#include "widget_manager.h"



WidgetManager::WidgetManager()
    :QWidget(nullptr)
{
    setFixedSize(1000,900);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);


     stack=new QStackedWidget();

     QDesktopWidget *desk=QApplication::desktop();
     move((desk->width()-1000)/2,(desk->height()-800)/2);
     initPage();
     initconnect();
     QVBoxLayout *layout = new QVBoxLayout();
     layout->setMargin(100);
     layout->addWidget(stack);
     setLayout(layout);
     //stack->setCurrentIndex(1);
     emit isNeedInitCam();

}
void WidgetManager::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        this->bPressFlag=true;
        this->mouseStartPoint=event->globalPos();
        this->windowTopLeftPOint=this->frameGeometry().topLeft();
    }
}

void WidgetManager::mouseMoveEvent(QMouseEvent *event)
{
    if(this->bPressFlag)
    {
        //qDebug()<<"move"<<endl;
        QPoint distance=event->globalPos()-mouseStartPoint;
        this->move(windowTopLeftPOint+distance);
    }
}

void WidgetManager::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        this->bPressFlag=false;
    }
}
void WidgetManager::initconnect()
{

    connect(this,SIGNAL(isNeedInitCam()),&SetPageController::getInstance(),SLOT(checkCamInfo()));
    connect(&SetPageController::getInstance(),SIGNAL(checkCamRet(bool)),this,SLOT(setFirstPage(bool)));
    connect(setPage,SIGNAL(finishCamSet(int)),this,SLOT(changePage(int)));
    connect(mainPage,SIGNAL(changeToSet(int)),this,SLOT(changePage(int)));
    connect(this,SIGNAL(changePage()),&MainPageController::getInstance(),SLOT(noSendImg()));
    connect(this,SIGNAL(startCamera()),&MainPageController::getInstance(),SLOT(startFdThread()));
    connect(playbackMenu,SIGNAL(pageToMain(int)),this,SLOT(changePage(int)));
    connect(imgMenu,SIGNAL(pageToMain(int)),this,SLOT(changePage(int)));
    connect(transcodePage,SIGNAL(pageToMain(int)),this,SLOT(changePage(int)));
    connect(imgMenu,SIGNAL(lookUpImg(int,QString)),this,SLOT(ImgShow(int,QString)));
    connect(playbackMenu,SIGNAL(videoPlay(int,QString)),this,SLOT(VideoPlay(int,QString)));
    connect(this,SIGNAL(restartCamera()),&MainPageController::getInstance(),SLOT(restart()));
    connect(imgPage,SIGNAL(returnToMenu(int)),this,SLOT(changePage(int)));
    connect(playPage,SIGNAL(returnToMenu(int)),this,SLOT(changePage(int)));
    connect(this,SIGNAL(initTable()),&MenuController::getInstance(),SLOT(getVideoInfo()));
    connect(this,SIGNAL(initImgTable()),&MenuController::getInstance(),SLOT(getImgInfo()));
    connect(this,SIGNAL(initListWidget()),&TranscodePageController::getInstance(),SLOT(getVideoInfo()));
    connect(registPage,SIGNAL(pageToMain(int)),this,SLOT(changePage(int)));
    connect(this,SIGNAL(findNewId()),&UserController::getInstance(),SLOT(getNewId()));
}

void WidgetManager::initPage()
{
    mainPage=new MainPage(this);
    setPage=new SetPage(this);
    //loginPage=new LoginPage(this);
    playbackMenu=new PlaybackMenuPage(this);
    imgMenu=new ImgMenuPage(this);
    imgPage=new ImgPage(this);
    playPage=new PlayPage(this);
    transcodePage=new TranscodePage(this);
    registPage=new RegisterPage(this);

    stack->addWidget(mainPage);//0
    stack->addWidget(setPage);
    stack->addWidget(playbackMenu);
    stack->addWidget(imgMenu);
    stack->addWidget(imgPage);
    stack->addWidget(playPage);//5
    stack->addWidget(transcodePage);
    stack->addWidget(registPage);
}

void WidgetManager::changePage(int index)
{
    if(stack->currentIndex()==0&&index!=0)
    {
       emit changePage();

    }
    if(index==0)
    {

        emit restartCamera();

    }
    if(index==2)
    {
        emit initTable();
    }
    if(index==3)
    {
        emit initImgTable();
    }
    if(index==6)
    {
        emit initListWidget();
    }
    if(index==7)
    {
        emit findNewId();
    }
    stack->setCurrentIndex(index);

}

void WidgetManager::setFirstPage(bool isNull)
{

    if(isNull)
    {
        stack->setCurrentIndex(1);
    }
    else
    {
        stack->setCurrentIndex(0);
        emit startCamera();
    }
}

void WidgetManager::ImgShow(int index, QString name)
{

    imgPage->setImg(name);
    changePage(index);
}

void WidgetManager::VideoPlay(int index, QString name)
{

    changePage(index);
    playPage->setSources(name);
}

