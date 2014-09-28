#include "fireball.h"
#include <iostream>
#include <QDebug>
#include <QPixmap>

FireBall::FireBall(): angle(-M_PI/2)
{
}

QRectF FireBall::boundingRect() const
{
    return QRectF(0,0,20,20);
}

QPainterPath FireBall::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}
void FireBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),QPixmap ("4.gif"),boundingRect());
}
