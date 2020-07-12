#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include "line_edit.h"
#include "user_controller.h"

#include <QLabel>
#include <QWidget>



class LoginPage:public QDialog
{
    Q_OBJECT
public:
    LoginPage(QWidget *parent=nullptr);
signals:
    void checkId(QString);
    void sendLoginInfo(QString,QString);
    void logined(bool);
    void pageToRegister(int);
public slots:
    void setNameTips(bool isExist);
    void login();
    void loginRet(bool isSuccess);
    void closeLogin();
    void toRegister();
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
    QPushButton *loginBtn;
    QPushButton *registBtn;
    QPushButton *returnBtn;
    QLabel *checkNameTips;

    QPushButton *forgetPwd;

};

#endif // LOGINPAGE_H
