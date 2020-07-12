#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include "line_edit.h"
#include "user_controller.h"

#include <QSlider>
#include <QWidget>

class RegisterPage:public QWidget
{
    Q_OBJECT
public:
    RegisterPage(QWidget *parent=nullptr);
signals:
    //void findNewId();
    void sendRegistInfo(QString,QString,QString);
    void pageToMain(int);
public slots:
    void setIdEdit(int newId);
    void regist();
    void getRegistRet(bool ret);
    void closeRegist();
protected:
    void initWidget();
    void initLayout();
    void initConnect();
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual bool eventFilter(QObject *watched, QEvent *e) override;
private:
    QLabel *bgLab;
    LineEdit *nameEdit;
    LineEdit *pwdEdit;
    LineEdit *re_pwdEdit;
    QPushButton *registBtn;
    QPushButton *returnBtn;
    LineEdit *idEdit;
    QLabel *checkPwdTips;
    QLabel *checkSliderTips;
    QSlider *checkSlider;
};

#endif // REGISTERPAGE_H
