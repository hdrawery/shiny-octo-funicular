#include "img_label.h"

#include <QPainter>



ImgLabel::ImgLabel(QWidget *parent)
    :QLabel(parent)
{
    mask=new QLabel(this);
    selected=new QLabel(this);
    inittMask();
    mask->setHidden(true);
    setCursor(QCursor(Qt::PointingHandCursor));
    selected->setPixmap(QPixmap(":/img/img/selected.png"));
    selected->setGeometry(223,5,30,30);
    selected->setHidden(true);
}

void ImgLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!img.isNull())
    {
        painter.drawImage(QRect(0,0,img.width(),img.height()),img);
    }
    mask->raise();

}

void ImgLabel::setImg(QImage img)
{
    this->img=img.scaled(258,143);
    this->update();
}

void ImgLabel::setText(QString text)
{
    mask->setText(text);
}

QString ImgLabel::getText()
{
    return mask->text();
}

void ImgLabel::inittMask()
{
    mask->setGeometry(0,100,258,43);
    mask->setStyleSheet("background-color:rgba(92,110,120,0.7);font-family:Comic Sans MS;color:white;");
    mask->setContentsMargins(20,0,0,0);

}

void ImgLabel::mousePressEvent(QMouseEvent *event)
{
    emit clicked(this);
}

void ImgLabel::enterEvent(QEvent *)
{
    mask->setHidden(false);
}

void ImgLabel::leaveEvent(QEvent *)
{
    mask->setHidden(true);
}

void ImgLabel::focusInEvent(QFocusEvent *event)
{
    selected->raise();
    selected->setHidden(false);
}

void ImgLabel::focusOutEvent(QFocusEvent *event)
{
    selected->raise();
    selected->setHidden(true);
}



