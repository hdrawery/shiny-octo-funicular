#include "line_edit.h"

LineEdit::LineEdit(QPixmap *pixmap,editType type, QWidget *parent)
    :QLineEdit(parent)
{
    this->type=type;
    initWidget();
    icon->setPixmap(*pixmap);


    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 2);
    shadow_effect->setColor(QColor(159, 167, 180));
    shadow_effect->setBlurRadius(10);

    setGraphicsEffect(shadow_effect);

    initLayout();
    if(type==PATH)
    {
        connect(functBtn,SIGNAL(clicked(bool)),this,SLOT(setPath()));
    }

}

void LineEdit::setPath()
{
    QString path=QFileDialog::getExistingDirectory(this,"Open Directory","/",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);

    setText(path);
}

void LineEdit::initWidget()
{
    this->icon=new QLabel(this);
    if(type==PATH||type==PASSWORD)
    {
        this->functBtn=new QPushButton(this);
        functBtn->setObjectName("editToolBtn");
        //functBtn->setFixedSize(36,36);
    }
}
void LineEdit::initLayout()
{
    setFixedSize(345,55);
    QHBoxLayout *layout=new QHBoxLayout();

    layout->addWidget(icon,0,Qt::AlignVCenter|Qt::AlignLeft);
    layout->setContentsMargins(10,0,10,0);
    setLayout(layout);
    if(type==PATH||type==PASSWORD)
    {
        functBtn->setCursor(QCursor(Qt::PointingHandCursor));
        if(type==PATH)
        {
            functBtn->setIcon(QIcon(QPixmap(":/img/img/choosePath.jpg")));
            functBtn->setIconSize(QSize(36,36));
            functBtn->setGeometry(300,10,36,36);
        }
        if(type==PASSWORD)
        {
            functBtn->setIcon(QIcon(QPixmap(":/img/img/pwd_hide.jpg")));
            functBtn->setIconSize(QSize(25,25));
            isShow=false;
            setEchoMode(QLineEdit::Password);
            functBtn->setGeometry(300,15,25,25);
        }

        functBtn->installEventFilter(this);
    }
}
bool LineEdit::eventFilter(QObject *watched, QEvent *e)
{

    if(watched==functBtn)
    {
        if(type==PATH)
        {
            if(e->type()==QEvent::MouseButtonPress)
            {
                functBtn->setIcon(QIcon(QPixmap(":/img/img/choosePath_onclick.jpg")));
            }
            else if(e->type()==QEvent::MouseButtonRelease)
            {
                functBtn->setIcon(QIcon(QPixmap(":/img/img/choosePath.jpg")));
            }
            functBtn->setIconSize(QSize(36,36));
        }
        else if(type==PASSWORD)
        {
            if(e->type()==QEvent::MouseButtonPress)
            {
                if(!isShow)
                {
                    functBtn->setIcon(QIcon(QPixmap(":/img/img/pwd_show.jpg")));
                    setEchoMode(QLineEdit::Normal);
                }
                else
                {
                    functBtn->setIcon(QIcon(QPixmap(":/img/img/pwd_hide.jpg")));
                    setEchoMode(QLineEdit::Password);
                }
                isShow=!isShow;
                functBtn->setIconSize(QSize(25,25));
            }
        }

    }

    return QWidget::eventFilter(watched,e);
}
