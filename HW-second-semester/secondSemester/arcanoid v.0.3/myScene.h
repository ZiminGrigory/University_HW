
#pragma once
#include "platform.h"
#include "block.h"
#include "fireball.h"
#include <QGraphicsScene>
class MyScene: public QGraphicsScene
{
public:
    MyScene(QObject *parent = 0);
    ~MyScene();
    void keyPress(int event);

private:
    FireBall *fireBall;
    void addBlocks();
    Platform *platform;
    bool isSpacePressed;
};
