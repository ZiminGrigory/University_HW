#include "platform.h"
#include <iostream>
#include <QDebug>
#include <QPixmap>

Platform::Platform()
{
}

QRectF Platform::boundingRect() const
{
    return QRectF(0,0,80,15);
}

QPainterPath Platform::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Platform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),QPixmap (":/2.gif"),boundingRect());
}



