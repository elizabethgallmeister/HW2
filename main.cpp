#include "mainwindow.h"

#include <QApplication>

// here is a comment.
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
