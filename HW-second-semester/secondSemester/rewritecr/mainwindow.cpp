#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), countClick(0)
{
    ui->setupUi(this);
    ui->pushButton->setText("");
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    ui->pushButton_6->setText("");
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    ui->pushButton_9->setText("");

    mapper = new QSignalMapper (this);
    connect(ui->pushButton, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->pushButton, 1);
//    connect(ui->pushButton_2, SIGNAL(clicked()), mapper, SLOT(map()));
//    mapper->setMapping(ui->pushButton_2, ui->pushButton_2);
//    connect(ui->pushButton_3, SIGNAL(clicked()), mapper, SLOT(map()));
//    mapper->setMapping(ui->pushButton_3, ui->pushButton_3);
//    connect(ui->pushButton_4, SIGNAL(clicked()), mapper, SLOT(map()));
//    mapper->setMapping(ui->pushButton_4, ui->pushButton_4);
//    connect(ui->pushButton_5, SIGNAL(clicked()), mapper, SLOT(map()));
//    mapper->setMapping(ui->pushButton_5, ui->pushButton_5);
//    connect(ui->pushButton_6, SIGNAL(clicked()), mapper, SLOT(map()));
//    mapper->setMapping(ui->pushButton_6, ui->pushButton_6);
//    connect(ui->pushButton_7, SIGNAL(clicked()), mapper, SLOT(map()));
//    mapper->setMapping(ui->pushButton_7, ui->pushButton_7);
//    connect(ui->pushButton_8, SIGNAL(clicked()), mapper, SLOT(map()));
//    mapper->setMapping(ui->pushButton_8, ui->pushButton_8);
//    connect(ui->pushButton_9, SIGNAL(clicked()), mapper, SLOT(map()));
//    mapper->setMapping(ui->pushButton_9, ui->pushButton_9);
    connect(mapper, SIGNAL(mapped(int)),
            this, SLOT(clickedPushButton1()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::clickedPushButton(QPushButton *ob)
{
    countClick++;
    if (countClick %2 == 1)
        ob->setText("x");
    else
        ob->setText("o");
    ob->blockSignals(true);
    if (countClick == 9)
        emit (end1());
}

void MainWindow::clickedPushButton1()
{
    qDebug() << "212";
}
