#include "videoplayer.h"
#include <QApplication>
#include "mainwindow.h"
#include "asdf.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    asdf x;
    VideoPlayer w;
    w.verbinden(&x);
    x.show();
    w.show();


    return a.exec();
}
