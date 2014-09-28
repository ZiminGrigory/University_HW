#include "fireball.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QtCore>
#include <QPixmap>

void FireBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    setPixmap(QPixmap("fireBall.gif"));
}

void FireBall::advance(int step)
{

}
