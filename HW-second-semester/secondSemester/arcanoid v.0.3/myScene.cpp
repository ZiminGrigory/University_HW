#include "myScene.h"
#include <iostream>
#include <QDebug>
enum
{
    A = 1060,
    D = 1042
};
MyScene::MyScene(QObject *parent): QGraphicsScene(parent),isSpacePressed(false)
{
    this->setSceneRect(5,5,295,395);
    addBlocks();
    platform = new Platform;
    platform->setPos(this->width()/2 - platform->boundingRect().width()/2,
                     this->height() - platform->boundingRect().height());
    this->addItem(platform);
    fireBall = new FireBall;
    fireBall->setPos(this->width()/2 - fireBall->boundingRect().width()/2,
                     this->height() - platform->boundingRect().height()- 0.95*fireBall->boundingRect().height());
    this->addItem(fireBall);
    fireBall->setBorder();
}

MyScene::~MyScene()
{
    delete platform;
    delete fireBall;
    this->clear();
}

void MyScene::addBlocks()
{
    int x = 7;
    int y = 10;
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            QGraphicsItem *item = new Block;
            item->setPos(x,y);
            if (i != 5)
                x += 49;
            this->addItem(item);
        }
        x = 7;
        y += 25;
    }
}

void MyScene::keyPress(int event)
{
    QPointF pointPlatform = platform->pos();
    QPointF pointFireBall = fireBall->pos();
    switch (event)
    {
        case Qt::Key_Space:
            isSpacePressed = true;
            break;
        case A:
            if (pointPlatform.x() >= this->sceneRect().left()){
                pointPlatform.setX(pointPlatform.x()-6);
                if(!isSpacePressed)
                pointFireBall.setX(pointFireBall.x()-6);
            }
            else
                return;
            break;
        case D:
            if (pointPlatform.x() <= this->sceneRect().right() - platform->boundingRect().width()){
                pointPlatform.setX(pointPlatform.x()+6);
                if(!isSpacePressed)
                    pointFireBall.setX(pointFireBall.x()+6);
            }
            else
                return;
            break;
    }
    platform->setPos(pointPlatform.x(),pointPlatform.y());
    fireBall->setPos(pointFireBall.x(),pointFireBall.y());
    update();

}

