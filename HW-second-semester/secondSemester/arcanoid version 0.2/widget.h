#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include "platform.h"
#include "block.h"
#include "fireball.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    Platform *platform;
    FireBall *fireBall;
    bool isSpacePressed;
    QTimer *timer;
    int countBlocks;
signals:
    void spaceWasPressed();
    void gameOver();
    void victory();
private slots:
    void theEnd();
    void happyEnd();
    void startBall();
    void ballAdvance();
    QGraphicsItem *itemCollidesWith(QGraphicsItem * item);



};

#endif // WIDGET_H
