#include <QApplication>
#include "myform.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyForm * window = new MyForm;
    window->setFixedSize(480,640);
    window->show();

    
    return app.exec();
}
