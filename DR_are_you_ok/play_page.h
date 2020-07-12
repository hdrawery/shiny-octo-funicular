#ifndef PLAYPAGE_H
#define PLAYPAGE_H

#include "video_bar.h"
#include "video_label.h"
#include "play_page_controller.h"

#include <QWidget>

class PlayPage:public QWidget
{
    Q_OBJECT
public:
    PlayPage(QWidget *parent=nullptr);
    void setSources(QString name);
signals:
    void openSources(QString);
    void sendSaveImg(QImage);
    void transcodeSources(QString);
    void returnToMenu(int);
protected:
    void initWidget();
    void initLayout();
    void initConnect();
    void initBackground();

    virtual void resizeEvent(QResizeEvent *event) override;
public slots:
    void setIconStop();
    void sendSaveScreenShot();
    void transcode();
    void closePage();
private:
    QLabel *bgLab;
    QPushButton *returnBtn;
    QPushButton *exportBtn;
    QPushButton *screenshotBtn;
    VideoBar *videoBar;
    VideoLabel *videoLab;
    QString sources;
};

#endif // PLAYPAGE_H
