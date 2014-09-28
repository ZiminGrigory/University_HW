#include "fireball.h"
#include <iostream>
#include <QDebug>
#include <QPixmap>
#include "block.h"
#include "platform.h"

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

void FireBall::setBorder()
{
    topBorder = this->y()- this->y();
    leftBorder = this->x() - this->x();
    rightBorder = this->x()*2;
    bottomBorder = this->y() + 0.25*this->boundingRect().height();
}

void FireBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),QPixmap (":/4.gif"),boundingRect());
}

void FireBall::advance(int phase)
{
    QPointF point = this->pos();
    QList <QGraphicsItem*> list = this->collidingItems();
    Block* block = NULL;
    Platform* platform = NULL;

    if (list.length() >= 1)
    {
        block = dynamic_cast<Block*>(list.at(0));
        platform = dynamic_cast<Platform*>(list.at(0));
    }

    if(platform)
    {
        angle *= -1;
        if (this->x() <= (platform->x()
                          + platform->boundingRect().width()/3 - this->boundingRect().width()))
            angle += M_PI/6;
        if (this->x() >= (platform->x() + 2*platform->boundingRect().width()/3))
            angle -= M_PI/6;
    }

    if(block)
    {
        angle *= -1;
        block->~QGraphicsItem();
        block = NULL;
    }

    if (point.y() >= bottomBorder)
        this->hide();

    if (point.y() <= topBorder)
        angle *= -1;

    if (point.x() <= leftBorder
        || point.x() >= rightBorder)//waals
    {
        if(this->angle > 0)
            this->angle = M_PI - this->angle;
        if(this->angle < 0)
            this->angle = - M_PI - this->angle;
    }
    point.setX(point.x()+cos(this->angle)*4);
    point.setY(point.y()-sin(this->angle)*4);
    this->setPos(point.x(),point.y());

    update();

}
