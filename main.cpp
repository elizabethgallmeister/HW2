#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // manages execution and exiting of Qt Program
    MainWindow w;
    w.show();
    return a.exec(); // controls exiting the program
}
