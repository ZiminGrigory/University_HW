#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QtCore>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    newGame();
}

Widget::~Widget()
{
    delete ui;
    delete scene;
}

void Widget::newGame()
{
    scene = new MyScene;
    wasSpacePressed = false;
    timer = new QTimer(this);
    ui->graphicsView->setMinimumSize(300,400);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/1.jpg"));
    ui->graphicsView->setCacheMode(QGraphicsView::CacheNone);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space && !wasSpacePressed)
    {
        wasSpacePressed = true;
        timer->start(25);
    }
    scene->keyPress(event->key());
}


