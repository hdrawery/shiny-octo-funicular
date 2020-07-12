#include "animation_view.h"

AnimationView::AnimationView()
{
    setFixedSize(650,600);
    setWindowFlags(Qt::FramelessWindowHint);
    setBackgroundBrush(QPixmap(":/img/img/animation_bg.jpg"));

    scene=new QGraphicsScene();
    setScene(scene);
    setSceneRect(0,0,width()-2,height()-2);

    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),5,5);
    setMask(bmp);

    number=0;


    timer=new QTimer();
    timer->start(80);
    stopTimer=new QTimer();
    stopTimer->start(80);

    initItem();
    initConnect();
}

void AnimationView::initItem()
{
    obstacle=new AnimationItem(":/img/img/obstacle.png",false,scene);
    scene->addItem(obstacle);
    obstacle->setPos(width()/2+obstacle->getWidth()+30,height()/2+obstacle->getHeight()*5/2);

    car=new AnimationItem(":/img/img/car.png",true,scene);
    scene->addItem(car);
    car->setPos(car->getWidth()+20,height()/2+obstacle->getHeight()*2+10);
}

void AnimationView::initConnect()
{
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(stopTimer,SIGNAL(timeout()),this,SLOT(count()));
    connect(this,SIGNAL(animationFinished()),this,SLOT(close()));
    //connect(this,SIGNAL(animationFinished()),manager,SLOT(show()));
}
void AnimationView::count()
{
    number++;
    if(number==25)
    {

        manager=new WidgetManager();
        connect(this,SIGNAL(animationFinished()),manager,SLOT(show()));
        stopTimer->stop();
        emit animationFinished();
    }
}
