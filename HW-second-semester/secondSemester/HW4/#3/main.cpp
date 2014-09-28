/**
 * @version 1.0
 *The second task. Working version.
 *calculator can do all the functions declared in the buttons.
 *you can tackle consistently, such as 4 + 4 - 2 - 2.5 (not necessary every time to poke at "equal").
 *But there is no operator precedence.
*/

#include <QtGui/QApplication>
#include "calculator.h"
#include "calculating.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.show();
    return a.exec();
}
