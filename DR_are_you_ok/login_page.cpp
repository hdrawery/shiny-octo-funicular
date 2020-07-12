#include "login_page.h"

#include <QBitmap>
#include <QPainter>
#include <QRegExpValidator>


LoginPage::LoginPage(QWidget *parent)
    :QDialog(parent)
{
    setFixedSize(549,400);

    bgLab=new QLabel(this);
    bgLab->setObjectName("bg");
    bgLab->setScaledContents(true);

    QBitmap bmp(549,400);
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),5,5);
    setMask(bmp);

    initWidget();
    initLayout();
    initConnect();
}

void LoginPage::setNameTips(bool isExist)
{
    if(isExist)
    {
        checkNameTips->setPixmap(QPixmap(":/img/img/right.png"));
    }
    else
    {
        checkNameTips->setPixmap(QPixmap(":/img/img/wrong.png"));
    }
}

void LoginPage::login()
{
    emit sendLoginInfo(nameEdit->text(),pwdEdit->text());
}

void LoginPage::loginRet(bool isSuccess)
{
    if(isSuccess)
    {
        nameEdit->clear();
        pwdEdit->clear();
        emit logined(true);
        close();
    }
    else
    {
        nameEdit->setFocus();
    }
}

void LoginPage::closeLogin()
{
    nameEdit->clear();
    pwdEdit->clear();
    emit logined(false);
    close();
}

void LoginPage::toRegister()
{
    emit pageToRegister(7);
    nameEdit->clear();
    pwdEdit->clear();
    close();
}

void LoginPage::initWidget()
{
    QPixmap *pix1=new QPixmap(":/img/img/id.jpg");
    nameEdit=new LineEdit(pix1,COMMON,this);
    QPixmap *pix2=new QPixmap(":/img/img/pwd.jpg");
    pwdEdit=new LineEdit(pix2,PASSWORD,this);
    forgetPwd=new QPushButton("forget password?",this);
    returnBtn=new QPushButton("return",this);
    loginBtn=new QPushButton("log in",this);
    registBtn=new QPushButton("register",this);
    checkNameTips=new QLabel(this);

}

void LoginPage::initLayout()
{
    registBtn->setObjectName("styleOne");
    returnBtn->setObjectName("styleTwo");
    loginBtn->setObjectName("styleThree");

    returnBtn->setGeometry(0,340,183,60);
    returnBtn->setCursor(QCursor(Qt::PointingHandCursor));
    registBtn->setGeometry(183,340,183,60);
    registBtn->setCursor(QCursor(Qt::PointingHandCursor));
    loginBtn->setGeometry(366,340,183,60);
    loginBtn->setCursor(QCursor(Qt::PointingHandCursor));

    nameEdit->setGeometry(102,85,345,55);
    nameEdit->installEventFilter(this);
    pwdEdit->setGeometry(102,185,345,55);
    pwdEdit->setMaxLength(16);
    QRegExpValidator *pattern= new QRegExpValidator(QRegExp("^[0-9]*[1-9][0-9]*$"), this);
    nameEdit->setValidator(pattern);
    QRegExpValidator *pattern2= new QRegExpValidator(QRegExp("^[A-Za-z0-9]+$"), this);
    pwdEdit->setValidator(pattern2);

    forgetPwd->setObjectName("labBtn");
    forgetPwd->setCursor(QCursor(Qt::PointingHandCursor));
    forgetPwd->setGeometry(175,250,190,60);

//    checkNameTips->setPixmap(QPixmap(":/img/img/right.png"));
    checkNameTips->setGeometry(460,105,25,25);
    //checkPwdTips->setPixmap(QPixmap(":/img/img/right.png"));
//    checkPwdTips->setGeometry(460,205,25,25);
}

void LoginPage::initConnect()
{
    connect(this,SIGNAL(checkId(QString)),&UserController::getInstance(),SLOT(checkId(QString)));
    connect(&UserController::getInstance(),SIGNAL(isIdExist(bool)),this,SLOT(setNameTips(bool)));
    connect(loginBtn,SIGNAL(clicked(bool)),this,SLOT(login()));
    connect(this,SIGNAL(sendLoginInfo(QString,QString)),&UserController::getInstance(),SLOT(loginCheck(QString,QString)));
    connect(&UserController::getInstance(),SIGNAL(checkRet(bool)),this,SLOT(loginRet(bool)));
    connect(returnBtn,SIGNAL(clicked(bool)),this,SLOT(closeLogin()));
    connect(this,SIGNAL(logined(bool)),&UserController::getInstance(),SLOT(setIsLogined(bool)));
    connect(registBtn,SIGNAL(clicked(bool)),this,SLOT(toRegister()));
}

void LoginPage::resizeEvent(QResizeEvent *event)
{
    bgLab->resize(this->size());
}

bool LoginPage::eventFilter(QObject *watched, QEvent *e)
{
    if(watched==nameEdit)
    {
        if(e->type()==QEvent::FocusOut)
        {
            if(nameEdit->text()!="")
            {
                emit checkId(nameEdit->text());
            }

        }
    }


   return QWidget::eventFilter(watched,e);
}
