#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    //intervalarth::interval a;
    //a = new intervalarth::interval();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
