#ifndef PLATFORM_H
#define PLATFORM_H
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
class Platform : public QGraphicsItem
{
public:
    Platform();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // PLATFORM_H
