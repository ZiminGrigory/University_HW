#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsItem>
#include <QPainter>

class Block : public QGraphicsItem
{
public:
    Block();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


};

#endif // BLOCK_H
