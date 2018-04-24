#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(0,0,700,400);
    w.setFixedSize(700,400);
    w.show();

    return a.exec();
}
