#ifndef ANIMATIONITEM_H
#define ANIMATIONITEM_H


#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>


class AnimationItem : public QGraphicsItem
{


public:
    AnimationItem(QString imgPath,bool isMove,QGraphicsScene *scene);
    QRectF boundingRect()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
    void advance(int phase)override;
    int getWidth();
    int getHeight();
    void doCollding();
private:
    QPixmap img;
    bool isMove;
    QGraphicsScene* scene;
};

#endif // ANIMATIONITEM_H
