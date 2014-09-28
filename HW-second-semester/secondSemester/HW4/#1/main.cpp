/**
 * @version 1.0
 *The first task. Working version.
 *
 *
 */
//I did not write a single line, all made ??in the form editor.
#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
