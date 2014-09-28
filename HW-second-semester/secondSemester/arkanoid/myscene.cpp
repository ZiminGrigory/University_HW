#include "myscene.h"

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QtCore>

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{
    QTimer timer;
    QGraphicsScene::connect(&timer, SIGNAL(timeout()), this, SLOT(advance()));
    timer.start(1000 / 33);
    makeFireBall();
    makeAsteroids();
    makeWalls();
    setBackgroundBrush(QBrush(QColor(255,255,255), QPixmap("test.jpg")));
}

void MyScene::keyPressEvent(QKeyEvent *keyEvent)
{
}

void MyScene::makeAsteroids()
{
}

void MyScene::makeWalls()
{
}

void MyScene::makePlatform()
{

}

QGraphicsItem *MyScene::itemCollidesWith(QGraphicsItem *item)
{
}


void MyScene::makeFireBall()
{
    fireball = new FireBall();
    fireball->setOffset(0.0,0.0);
    this->addItem(fireball);
}
