#pragma once
#include <QGraphicsPixmapItem>
#include <QPixmap>

class FireBall :public QGraphicsPixmapItem
{
public:
    FireBall(): angle(0), speed(0)
    {
        setOffset(0,0);
    }
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

public slots:
    void advance(int step);

private:
    qreal angle;
    qreal speed;
};
