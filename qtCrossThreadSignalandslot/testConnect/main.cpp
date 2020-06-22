#include "mainwindow.h"

#include <QApplication>
#include "Test.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
    Test w;
    w.show();
    return a.exec();
}
