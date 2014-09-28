/**
 * @version 1.0
 *The second task. Working version.
 *
 *
 */
//connections, signals and slots created in the Forms menu
#include <QtGui/QApplication>
#include "calc.h"
#include "calc.cpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calc w;
    w.show();

    return a.exec();
}
