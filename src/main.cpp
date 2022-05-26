#include "mainwindow.h"
#include "tab.h"
#include <QApplication>
#include <QDebug>
#include <cmath>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tab w;
    w.show();
    return a.exec();
}
