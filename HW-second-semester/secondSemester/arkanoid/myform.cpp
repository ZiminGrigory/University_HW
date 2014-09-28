#include "myform.h"
#include "myform.h"


MyForm::MyForm(QWidget *parent):QMainWindow(parent)
{
    setupUi(this);
    setWindowTitle("Arcanoid");
    scene = new MyScene;
    graphicsView->setFixedSize(440,630);
    graphicsView->setScene(scene);
}
