#ifndef VIDEOLISTWIDGET_H
#define VIDEOLISTWIDGET_H


#include <QLabel>
#include <QListWidget>
#include <QMenuBar>
#include <QPushButton>



class VideoListWidget:public QMenuBar
{
    Q_OBJECT
public:
    VideoListWidget(int width,QWidget *parent=nullptr);
    void initListWidget(QString cover);
    void clearList();
    void setNameList(QStringList v_name);
    QString getSelectedName();
signals:
   // void sendIndex(int);
    void findPrevious();
    void findNext();
public slots:
    void getListIndex(int currentRow);
    //void setSelectedText(QString name);
    void toFindPrevious();
    void toFindNext();
protected:
    void initWidget();
    void initLayout();
    void initConnect();
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    QLabel *bgLab;
    QListWidget *imgList;
    QPushButton *previous;
    QPushButton *next;
    QLabel *selected;
    QStringList name;


};

#endif // VIDEOLISTWIDGET_H
