#ifndef IMGLABEL_H
#define IMGLABEL_H

#include <QLabel>



class ImgLabel:public QLabel
{
    Q_OBJECT
public:
    ImgLabel(QWidget *parent=nullptr);
    void setImg(QImage img);
    void setText(QString text);
    QString getText();
signals:
    void clicked(ImgLabel *);
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void inittMask();
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void enterEvent(QEvent *) override;
    virtual void leaveEvent(QEvent *) override;
    virtual void focusInEvent(QFocusEvent *event) override;
    virtual void focusOutEvent(QFocusEvent *event) override;
private:
    QImage img;
    QLabel *mask;
    QLabel *selected;
    //bool isShow;
};

#endif // IMGLABEL_H
