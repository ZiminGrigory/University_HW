#pragma once
#include <QMainWindow>
#include "ui_myform.h"
#include "myscene.h"

class MyScene;

class MyForm : public QMainWindow, public Ui::MyForm
{
    Q_OBJECT
    
public:
    MyForm(QWidget *parent = 0);
    
private:
    MyScene * scene;
};
