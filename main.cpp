#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Set to foreground
    w.setWindowFlags(w.windowFlags() | Qt::WindowStaysOnTopHint);

    w.show();
    return a.exec();
}
