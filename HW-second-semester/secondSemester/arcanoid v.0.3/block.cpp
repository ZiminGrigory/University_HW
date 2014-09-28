#include "block.h"
#include <iostream>
#include <QDebug>
#include <QPixmap>

Block::Block()
{
}

QRectF Block::boundingRect() const
{
    return QRectF(0,0,45,20);
}

QPainterPath Block::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}
void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),QPixmap (":/3.gif"),boundingRect());
}
