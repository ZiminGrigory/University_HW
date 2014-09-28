#pragma once
#include <QGraphicsScene>
#include <QKeyEvent>
#include "fireball.h"

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyScene(QObject *parent = 0);
protected:
    virtual void keyPressEvent(QKeyEvent * keyEvent);

private:
    void makeFireBall();
    void makeAsteroids();
    void makeWalls();
    void makePlatform();
    QGraphicsItem * itemCollidesWith(QGraphicsItem * item);
    FireBall *fireball;
};
