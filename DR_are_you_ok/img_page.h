#ifndef IMGPAGE_H
#define IMGPAGE_H



#include "img_page_controller.h"

#include <QPainter>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class ImgPage:public QWidget
{
    Q_OBJECT
public:
    ImgPage(QWidget *parent=nullptr);
    void setImg(QString name);

signals:
    void previousImg(QString);
    void lastImg(QString);
    void findImgPath(QString);
    void returnToMenu(int);
public slots:
    void changeToPrevious();
    void changeToLast();
    void setSources(QString path);
    void closePage();
protected:
    void initWidget();
    void initConnect();
    void initLayout();
    virtual void paintEvent(QPaintEvent*event) override;
private:
    QLabel *imgLab;
    QPushButton *closeBtn;
    QPushButton *previous;
    QPushButton *last;
    QString sources;
};

#endif // IMGPAGE_H
