#ifndef TRANSCODEPAGE_H
#define TRANSCODEPAGE_H

#include "video_list_widget.h"
#include "transcode_page_controller.h"

#include <QCalendarWidget>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QWidget>

class TranscodePage:public QWidget
{
    Q_OBJECT
public:
    TranscodePage(QWidget *parent=nullptr);
signals:
    void initListWidget();
    void searchVideo(QString);
    void transcode(QString,QString,QString);
    void pageToMain(int);
    void videoClear();
protected:
    void initWidget();
    void initLayout();
    void initConnect();
    void initBackground();
    virtual void resizeEvent(QResizeEvent *event) override;

public slots:
    void chooseDate();
    void setDateSlot();
    void setPath();
    void setListWidget(QStringList name,QStringList cover);
    void search();
    void toTranscode();
    void initProgress(int max);
    void returnToMain();
private:
    QLabel *bgLab;
    QLineEdit *searchEdit;

    VideoListWidget *imgList;
    QProgressBar *progressBar;
    QPushButton *searchBtn;
    QPushButton *calendarBtn;
    QPushButton *returnBtn;
    QPushButton *okBtn;
    QCalendarWidget *calendar;

    QLabel *formatLab;
    QLabel *savePathLab;
    QComboBox *formatCombo;
    QLineEdit *fileEdit;
    QPushButton *fileBtn;
    bool isShow;
};

#endif // TRANSCODEPAGE_H
