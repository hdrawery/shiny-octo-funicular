#ifndef SETPAGE_H
#define SETPAGE_H

#include "line_edit.h"
#include "set_page_controller.h"

#include <QBitmap>
#include <QPainter>
#include <QRegExpValidator>
#include <QDesktopWidget>
#include <QApplication>
class SetPage:public QWidget
{
    Q_OBJECT
public:
    SetPage(QWidget *parent=nullptr);
signals:
    void askCamName();
    void applyCamSet(QString,QString,QString,QString);
    void finishCamSet(int);
    void askCamInfo();
public slots:
    void setCamName(QString name);
    void applySet();
    void initSetPage(QString video,QString img,QString interval);
    void cancelSet();
protected:
    void initWidget();
    void initLayout();
    void initConnect();
    virtual void resizeEvent(QResizeEvent *event) override;
private:
    QLabel *bgLab;
    LineEdit *videoSavePath;
    LineEdit *imgSavePath;
    LineEdit *timeInterval;
    LineEdit *camName;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *tips;
};

#endif // SETPAGE_H
