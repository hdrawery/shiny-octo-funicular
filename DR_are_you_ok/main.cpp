#include "animation_view.h"




#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QFile qss("://myQss.qss");

    if(qss.open(QFile::ReadOnly))
    {
        a.setStyleSheet(QLatin1String(qss.readAll()));
        qss.close();
    }


    AnimationView animation;

    animation.show();



    return a.exec();
}
