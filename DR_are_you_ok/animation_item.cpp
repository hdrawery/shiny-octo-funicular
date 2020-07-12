#include "animation_item.h"

AnimationItem::AnimationItem(QString imgPath, bool isMove, QGraphicsScene *scene)
{
    this->img.load(imgPath);
    this->isMove=isMove;
    this->scene=scene;
}

QRectF AnimationItem::boundingRect() const
{
    return QRect(-img.width()/2,0,img.width(),img.height());
}

void AnimationItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-img.width()/2,0,img);
}

void AnimationItem::advance(int phase)
{
    if(isMove)
    {
        QPointF point=mapToScene(0,0);
        if(collidingItems().count()>0)
        {
            isMove=false;
            doCollding();

        }
        else
        {
            this->setPos(point.x()+5,point.y());
        }
    }
}

int AnimationItem::getWidth()
{
    return img.width();
}

int AnimationItem::getHeight()
{
    return img.height();
}

void AnimationItem::doCollding()
{
    AnimationItem *title=new AnimationItem(":/img/img/title.png",false,nullptr);
    scene->addItem(title);
    title->setPos(title->getWidth()*3/4,title->getHeight()*3/2);
}
