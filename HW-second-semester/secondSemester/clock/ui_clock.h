/********************************************************************************
** Form generated from reading UI file 'clock.ui'
**
** Created: Sun 17. Mar 12:25:37 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCK_H
#define UI_CLOCK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clock
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Clock)
    {
        if (Clock->objectName().isEmpty())
            Clock->setObjectName(QString::fromUtf8("Clock"));
        Clock->resize(400, 300);
        centralWidget = new QWidget(Clock);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Clock->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Clock);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        Clock->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Clock);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Clock->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Clock);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Clock->setStatusBar(statusBar);

        retranslateUi(Clock);

        QMetaObject::connectSlotsByName(Clock);
    } // setupUi

    void retranslateUi(QMainWindow *Clock)
    {
        Clock->setWindowTitle(QApplication::translate("Clock", "Clock", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Clock: public Ui_Clock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCK_H
