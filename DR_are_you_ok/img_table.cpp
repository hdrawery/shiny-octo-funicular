#include "img_table.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPoint>
int ImgTable::nCurScroller=0;
ImgTable::ImgTable(QWidget *parent)
    :QTableWidget(parent)
{
    setRowCount(3);
    setColumnCount(3);
    verticalHeader()->setDefaultSectionSize(145);
    horizontalHeader()->setDefaultSectionSize(260);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    verticalHeader()->setVisible(false);
    horizontalHeader()->setVisible(false);
    setShowGrid(false);
    setSelectionMode(QAbstractItemView::SingleSelection);
    //pageValue=9;
    //max=0;

}

void ImgTable::setImgMap(QString key, QString value,int x,int y)
{



    ImgLabel *lab=new ImgLabel(this);
    QImage img;
    img.load(value);
    lab->setImg(img);
    lab->setText(key);
    setCellWidget(x,y,lab);

    connect(lab,SIGNAL(clicked(ImgLabel *)),this,SLOT(getImgFocus(ImgLabel *)));


}

QString ImgTable::getImgName()
{
    return imgName;
}

void ImgTable::resetImgName()
{
    imgName="";
}

void ImgTable::setScrollLength(int len)
{
    qDebug()<<len<<endl;
    if(len%9==0)
    {
        max=len/9;
    }
    else
    {
        max=len/9+1;
    }
    verticalScrollBar()->setMaximum(max+1);
}

void ImgTable::getImgFocus(ImgLabel *img)
{

    img->setFocus();
    imgName=img->getText();
    //qDebug()<<"name:"<<imgName<<endl;

}

void ImgTable::wheelEvent(QWheelEvent *event)
{

    int maxValue = verticalScrollBar()->maximum();
    nCurScroller = verticalScrollBar()->value();
//    qDebug()<<nCurScroller<<endl;
    if(event->delta()>0){//如果滚轮往上滚

        if(nCurScroller>0)
        {
            verticalScrollBar()->setSliderPosition(nCurScroller-1);
        }

        emit previous();
    }
    else
    {
      // nCurScroller+=3;
        if(nCurScroller<maxValue+1)
        {
            verticalScrollBar()->setSliderPosition(nCurScroller+1);
        }


       emit next();
    }
}



