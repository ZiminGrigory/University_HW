#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QtGui>

class Clock : public QWidget
{
    Q_OBJECT

public:
    Clock(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void pressedBox(bool value);
    void timeZoneChanged(int index);
private:
    int correctHour;
    QTimer *timer;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QGridLayout *layout;
};

#endif // CLOCK_H
