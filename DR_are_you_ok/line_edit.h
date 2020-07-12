#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QEvent>
#include <QFileDialog>

enum editType{COMMON,PASSWORD,PATH};
class LineEdit:public QLineEdit
{
    Q_OBJECT
public:
    LineEdit(QPixmap *pixmap,editType type,QWidget *parent=nullptr);
public slots:
    void setPath();
protected:
    void initWidget();
    void initLayout();
    virtual bool eventFilter(QObject *watched, QEvent *e) override;
private:
    QLabel *icon;
    QPushButton *functBtn;
    editType type;
    bool isShow;
};

#endif // LINEEDIT_H
