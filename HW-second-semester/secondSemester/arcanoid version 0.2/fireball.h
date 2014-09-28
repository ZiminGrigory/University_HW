#ifndef FIREBALL_H
#define FIREBALL_H
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
class FireBall   : public QGraphicsItem
{
public:
    FireBall();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double angle;

};
#endif // FIREBALL_H
