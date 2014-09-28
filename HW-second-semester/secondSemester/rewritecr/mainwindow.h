#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>
#include <QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void end1();
private slots:
    void clickedPushButton(QPushButton *ob);
    void clickedPushButton1();

private:
    QSignalMapper *mapper;
    Ui::MainWindow *ui;
    unsigned int countClick;

};

#endif // MAINWINDOW_H
