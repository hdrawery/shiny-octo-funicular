#ifndef IMGTABLE_H
#define IMGTABLE_H
#include "img_label.h"

#include <QTableWidget>
#include <QHeaderView>
#include <QScrollBar>
class ImgTable:public QTableWidget
{
    Q_OBJECT
public:
    ImgTable(QWidget *parent=nullptr);
    void setImgMap(QString key,QString value,int x,int y);
    QString getImgName();
    void resetImgName();
signals:
    void previous();
    void next();

public slots:
    void setScrollLength(int len);
    void getImgFocus(ImgLabel *img);
protected:
    virtual void wheelEvent(QWheelEvent*event) override;

private:
    int pageValue;
    static int nCurScroller;
    int max;
    QString imgName;
};

#endif // IMGTABLE_H
