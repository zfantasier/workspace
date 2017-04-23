#include "dialog1.h"
#include <QApplication>
#include <QDesktopWidget>//居中显示库
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog1 w;

    w.show();
    w.move((QApplication::desktop()->width() - w.width())/2,
               (QApplication::desktop()->height() - w.height())/2);
    return a.exec();
}
