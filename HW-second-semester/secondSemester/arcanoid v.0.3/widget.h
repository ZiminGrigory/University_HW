#ifndef WIDGET_H
#define WIDGET_H
#pragma once
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include "myScene.h"

namespace Ui
{
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void newGame();
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::Widget *ui;
    MyScene * scene;
    QTimer *timer;
    bool wasSpacePressed;
};

#endif // WIDGET_H
