#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QtCore>
enum
{
    A = 1060,
    D = 1042,
    Space = 32
};

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),isSpacePressed(false), countBlocks(30)
{
    ui->setupUi(this);
    ui->label->close();
    platform = new Platform;
    platform->setPos(110,370);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(5,5,295,395);
    scene->addItem(platform);
    platform->setData(0,"platform");
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(QPixmap("1.jpg"));
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    ui->lcdNumber->display(countBlocks);

    fireBall = new FireBall;
    fireBall->setPos(140,352);
    scene->addItem(fireBall);

    int x = 5;
    int y = 10;
    for (int j = 0; j < 5; j++){
        for (int i = 0; i < 6; i++)
        {
            QGraphicsItem *item = new Block;
            item->setPos(x,y);
            x += 50;
            scene->addItem(item);
            item->setData(0, "block");
        }
        x = 5;
        y += 25;
    }
    timer = new QTimer(this);
    connect(this,SIGNAL(spaceWasPressed()),this,SLOT(startBall()));
    connect(this,SIGNAL(gameOver()),this,SLOT(theEnd()));
    connect(this,SIGNAL(victory()),this,SLOT(happyEnd()));

}

Widget::~Widget()
{
    delete ui;
    delete platform;
    delete fireBall;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    QPointF pointPlatform = platform->pos();
    QPointF pointFireBall = fireBall->pos();
    if (event->key() == Space)
    {
        isSpacePressed = true;
        emit (spaceWasPressed());
    }
    if (event->key() == A)
    {
        if (pointPlatform.x() >= 4){
            pointPlatform.setX(pointPlatform.x()-6);
            if(isSpacePressed == false)
                pointFireBall.setX(pointFireBall.x()-6);
        }
        else
            return;
    }
    else if (event->key() == D)
    {
        if (pointPlatform.x() <= 218){
            pointPlatform.setX(pointPlatform.x()+6);
            if(isSpacePressed == false)
                pointFireBall.setX(pointFireBall.x()+6);
        }
        else
            return;
    }

    platform->setPos(pointPlatform.x(),pointPlatform.y());
    fireBall->setPos(pointFireBall.x(),pointFireBall.y());
    update();
}

void Widget::startBall()
{
    disconnect(this,SIGNAL(spaceWasPressed()),this,SLOT(startBall()));
    timer->start(20);
    connect(timer,SIGNAL(timeout()),this,SLOT(ballAdvance()));
}

void Widget::ballAdvance()
{
    double correctAngle = 0;
    QPointF pFB = fireBall->pos();//pointfireball
    if (pFB.y() >= 365)
        emit(gameOver());
    if (countBlocks == 0)
        emit(victory());
    QGraphicsItem * obstacle = itemCollidesWith(fireBall);
    if (fireBall) //with item
    {
        if (obstacle->data(0) == "block")
        {
            fireBall->angle = fireBall->angle*(-1);
            scene->removeItem(obstacle);
            countBlocks--;
            ui->lcdNumber->display(countBlocks);
        }
        if(obstacle->data(0) == "platform")
        {
            if (pFB.x() <= (platform->pos().x()+7))
                correctAngle = -M_PI/10;
            else if (pFB.x() >= (platform->pos().x()+51))
                correctAngle = M_PI/10;
            fireBall->angle = fireBall->angle*(-1) - correctAngle;
            fireBall->angle = fireBall->angle - int(fireBall->angle / (2*M_PI));
        }
    }
    if (pFB.x() <= 5 || pFB.x() >= 290)//waals
    {
        if(fireBall->angle > 0)
            fireBall->angle = M_PI - fireBall->angle;
        if(fireBall->angle < 0)
            fireBall->angle = - M_PI - fireBall->angle;
    }
    if (pFB.y() <= 5)
    {
        fireBall->angle = fireBall->angle*(-1);
    }
    pFB.setX(pFB.x()+cos(fireBall->angle)*4);
    pFB.setY(pFB.y()-sin(fireBall->angle)*4);
    fireBall->setPos(pFB.x(),pFB.y());
    update();
}

QGraphicsItem *Widget::itemCollidesWith(QGraphicsItem *item)
{
    QList<QGraphicsItem *> collisions = scene->collidingItems(item);
    foreach (QGraphicsItem * it, collisions)
    {
            if (it == item)
                 continue;
        return it;
    }
    return NULL;
}

void Widget::theEnd()
{
    disconnect(timer,SIGNAL(timeout()),this,SLOT(ballAdvance()));
    ui->label->setText("GAME OVER");
    ui->label->show();
}

void Widget::happyEnd()
{
    disconnect(timer,SIGNAL(timeout()),this,SLOT(ballAdvance()));
    ui->label->setText("YOU WoN");
    ui->label->show();
}





