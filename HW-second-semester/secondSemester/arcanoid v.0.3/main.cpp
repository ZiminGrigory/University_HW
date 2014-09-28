#include <QtGui/QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(sourse);
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Game version 0.3");
    w.show();
    
    return a.exec();
}
