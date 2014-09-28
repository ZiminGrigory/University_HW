#ifndef FIREBALL_H
#define FIREBALL_H
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <math.h>

class FireBall:public QGraphicsItem
{
public:
    FireBall();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    void setBorder();
private:
    double angle;
    double topBorder;
    double leftBorder;
    double rightBorder;
    double bottomBorder;
};
#endif // FIREBALL_H
