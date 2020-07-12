#include "video_list_widget.h"

#include <QEvent>

#include <QDebug>

VideoListWidget::VideoListWidget(int width, QWidget *parent)
    :QMenuBar(parent)
{
    setFixedSize(width,270);



    bgLab=new QLabel(this);
    bgLab->setObjectName("bg4");
    bgLab->setScaledContents(true);


    initWidget();
    initLayout();
    initConnect();





}

void VideoListWidget::initListWidget(QString cover)
{

    QListWidgetItem *imageItem1 = new QListWidgetItem;
//    QString url=path="/"+cover+".jpg";
     //为单元项设置属性
    imageItem1->setIcon(QIcon(cover));

    //重新设置单元项图片的宽度和高度
    imageItem1->setSizeHint(QSize(210,160));
    //将单元项添加到QListWidget中
    imgList->addItem(imageItem1);
}

void VideoListWidget::clearList()
{
    imgList->clear();
}

void VideoListWidget::setNameList(QStringList v_name)
{
    name.clear();
    name=v_name;
}

QString VideoListWidget::getSelectedName()
{
    int len=selected->text().size();
    return selected->text().mid(9,len-9);
}



void VideoListWidget::getListIndex(int currentRow)
{
    //qDebug()<<currentRow<<endl;
    if(currentRow>=0)
    {
        QString text="CHOOSE : "+name[currentRow];
        selected->setText(text);
    }

}



void VideoListWidget::toFindPrevious()
{
    emit findPrevious();
}

void VideoListWidget::toFindNext()
{
    emit findNext();
}

void VideoListWidget::initWidget()
{

    imgList=new QListWidget(this);
    previous=new QPushButton(this);
    next=new QPushButton(this);
    selected=new QLabel("CHOOSE : ",this);
}

void VideoListWidget::initLayout()
{
    previous->setGeometry(15,130,30,30);
    previous->setIcon(QIcon(QPixmap(":/img/img/previous_img.png")));
    previous->setIconSize(QSize(30,30));
    previous->setCursor(QCursor(Qt::PointingHandCursor));

    next->setGeometry(width()-45,130,30,30);
    next->setIcon(QIcon(QPixmap(":/img/img/last_img.png")));
    next->setIconSize(QSize(30,30));
    next->setCursor(QCursor(Qt::PointingHandCursor));

    selected->setObjectName("barLab");
    selected->setStyleSheet("font-family:Impact;font-size:20px;");
    selected->setGeometry(280,25,320,20);


    imgList->setViewMode(QListView::IconMode);
    imgList->setIconSize(QSize(220,160));
    imgList->setMovement(QListWidget::Static);
    imgList->setSpacing(15);
    imgList->setResizeMode(QListWidget::Adjust);
    imgList->setGeometry(50,70,700,160);
    imgList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    imgList->installEventFilter(this);


}

void VideoListWidget::initConnect()
{
    connect(imgList,SIGNAL(currentRowChanged(int)),this,SLOT(getListIndex(int)));
    connect(previous,SIGNAL(clicked(bool)),this,SLOT(toFindPrevious()));
    connect(next,SIGNAL(clicked(bool)),this,SLOT(toFindNext()));
}

void VideoListWidget::resizeEvent(QResizeEvent *event)
{
    bgLab->resize(this->size());
}

