#include "register_page.h"

#include <QBitmap>
#include <QPainter>
#include <QRegExpValidator>


RegisterPage::RegisterPage(QWidget *parent)
    :QWidget(parent)
{
    setFixedSize(550,680);
    setWindowFlags(Qt::FramelessWindowHint);

    bgLab=new QLabel(this);
    bgLab->setObjectName("bg");
    bgLab->setScaledContents(true);

    QBitmap bmp(550,680);
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),5,5);
    setMask(bmp);

    initWidget();
    initLayout();
    initConnect();

    //每次跳转到注册都要发送信号查ID
    //暂时写在这里
    //要改到界面管理
    //emit findNewId();
}

void RegisterPage::setIdEdit(int newId)
{
    idEdit->setText(QString::number(newId));
}

void RegisterPage::regist()
{
    if(checkSlider->value()==checkSlider->maximum())
    {
        emit sendRegistInfo(idEdit->text(),nameEdit->text(),pwdEdit->text());
    }

}

void RegisterPage::getRegistRet(bool ret)
{
    if(ret)
    {
        //注册成功，清空
        qDebug()<<ret<<endl;
        closeRegist();
    }
    else
    {
        nameEdit->setFocus();
    }
}

void RegisterPage::closeRegist()
{
    nameEdit->clear();
    pwdEdit->clear();
    re_pwdEdit->clear();
    checkSlider->setValue(0);
    checkPwdTips->setPixmap(QPixmap(""));
    checkSliderTips->setVisible(false);
    //跳转主界面
    emit pageToMain(0);
}

void RegisterPage::initWidget()
{

    QPixmap *pix1=new QPixmap(":/img/img/user.jpg");
    nameEdit=new LineEdit(pix1,COMMON,this);
    QPixmap *pix2=new QPixmap(":/img/img/pwd.jpg");
    pwdEdit=new LineEdit(pix2,PASSWORD,this);
    re_pwdEdit=new LineEdit(pix2,PASSWORD,this);
    QPixmap *pix3=new QPixmap(":/img/img/id.jpg");
    idEdit=new LineEdit(pix3,COMMON,this);
    returnBtn=new QPushButton("return",this);
    registBtn=new QPushButton("register",this);

    checkPwdTips=new QLabel(this);
    checkSlider=new QSlider(this);
    checkSliderTips=new QLabel(this);
}

void RegisterPage::initLayout()
{
    registBtn->setObjectName("styleOne");
    returnBtn->setObjectName("styleTwo");


    returnBtn->setGeometry(0,620,275,60);
    returnBtn->setCursor(QCursor(Qt::PointingHandCursor));
    registBtn->setGeometry(275,620,275,60);
    registBtn->setCursor(QCursor(Qt::PointingHandCursor));


    nameEdit->setGeometry(102,195,345,55);
    pwdEdit->setGeometry(102,295,345,55);
    pwdEdit->installEventFilter(this);
    re_pwdEdit->setGeometry(102,395,345,55);
    re_pwdEdit->installEventFilter(this);




    QRegExpValidator *pattern2= new QRegExpValidator(QRegExp("^[A-Za-z0-9]+$"), this);
    nameEdit->setValidator(pattern2);
    pwdEdit->setValidator(pattern2);
    re_pwdEdit->setValidator(pattern2);

    idEdit->setGeometry(102,95,345,55);
    idEdit->setReadOnly(true);

//    checkPwdTips->setPixmap(QPixmap(":/img/img/right.png"));
    checkPwdTips->setGeometry(460,415,25,25);

    checkSliderTips->setPixmap(QPixmap(":/img/img/right.png"));
    checkSliderTips->setGeometry(460,515,25,25);
    checkSliderTips->setVisible(false);

    checkSlider->setObjectName("check");
    checkSlider->setOrientation(Qt::Horizontal);
    checkSlider->setGeometry(102,500,345,45);
    checkSlider->installEventFilter(this);


    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 2);
    shadow_effect->setColor(QColor(159, 167, 180));
    shadow_effect->setBlurRadius(10);

    checkSlider->setGraphicsEffect(shadow_effect);

}
bool RegisterPage::eventFilter(QObject *watched, QEvent *e)
{
     if(watched==re_pwdEdit||watched==pwdEdit)
     {
         if(e->type()==QEvent::FocusOut)
         {

            if(re_pwdEdit->text()!=""&&re_pwdEdit->text()==pwdEdit->text())
            {
                checkPwdTips->setPixmap(QPixmap(":/img/img/right.png"));
            }
            else
            {
                checkPwdTips->setPixmap(QPixmap(":/img/img/wrong.png"));
            }

         }
     }
     if(watched==checkSlider)
     {
         if(checkSlider->value()==checkSlider->maximum())
         {
             checkSliderTips->setVisible(true);
         }
         else
         {
             checkSliderTips->setVisible(false);
         }
     }

    return QWidget::eventFilter(watched,e);
}
void RegisterPage::initConnect()
{

    connect(&UserController::getInstance(),SIGNAL(newId(int)),this,SLOT(setIdEdit(int)));
    connect(registBtn,SIGNAL(clicked(bool)),this,SLOT(regist()));
    connect(this,SIGNAL(sendRegistInfo(QString,QString,QString)),&UserController::getInstance(),SLOT(regist(QString,QString,QString)));
    connect(&UserController::getInstance(),SIGNAL(registIsSuccess(bool)),this,SLOT(getRegistRet(bool)));
    connect(returnBtn,SIGNAL(clicked(bool)),this,SLOT(closeRegist()));
}

void RegisterPage::resizeEvent(QResizeEvent *event)
{
    bgLab->resize(this->size());
}
