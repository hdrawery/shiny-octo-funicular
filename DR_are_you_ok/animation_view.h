#ifndef ANIMATIONVIEW_H
#define ANIMATIONVIEW_H

#include "animation_item.h"
#include "widget_manager.h"

#include <QGraphicsView>
#include <QTimer>
#include <QBitmap>

class AnimationView:public QGraphicsView
{
    Q_OBJECT
public:
    AnimationView();
    void initItem();
signals:
    void animationFinished();
public slots:
    void count();
protected:
    void initConnect();
private:
    QGraphicsScene *scene;
    AnimationItem *car;
    AnimationItem *obstacle;
    QTimer *timer;
    QTimer *stopTimer;
    int number;
    WidgetManager *manager;

};

#endif // ANIMATIONVIEW_H
