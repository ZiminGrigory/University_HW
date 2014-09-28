#include "clock.h"

enum{
    minus12 =0,
    minus11,
    minus10,
    minus9,
    minus8,
    minus7,
    minus6,
    minus5,
    minus4,
    minus3,
    minus2,
    minus1,
    zero,
    plus1,
    plus2,
    plus3,
    plus4,
    plus5,
    plus6,
    plus7,
    plus8,
    plus9,
    plus10,
    plus11,
    plus12,
    plus13,
    plus14
};

Clock::Clock(QWidget *parent)
    : QWidget(parent), correctHour(0)
{
    timer = new QTimer(this);//create a timer
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));//connect update widget by timer
    timer->start(50);
    setWindowTitle(tr("Analog Clock"));
    setMinimumSize(360, 300);
    setMaximumSize(360, 300);

    checkBox = new QCheckBox(this);
    checkBox->setText("change UTS");

    comboBox = new QComboBox(this);
    comboBox->setMaximumSize(50,50);
    for (int i = -12; i <= 14; i++)
    {
        QString c;
        if (i > 0)
            c = "+";
        comboBox->addItem(c + QString::number(i));
    }
    layout = new QGridLayout(this);
    layout->addWidget(checkBox,0,0,0,4);
    layout->addWidget(comboBox,0,5);
    setLayout(layout);
    comboBox->hide();
    connect(checkBox,SIGNAL(clicked(bool)),this, SLOT(pressedBox(bool)));
    connect(comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(timeZoneChanged(int)));
}


void Clock::paintEvent(QPaintEvent *)
{
    //points that create the arrow
    static const QPoint hourHand[7] = {
        QPoint(4, 8),
        QPoint(-4, 8),
        QPoint(-4, -40),
        QPoint(-6, -40),
        QPoint(-0, -50),
        QPoint(6, -40),
        QPoint(4, -40)
    };
    static const QPoint minuteHand[7] = {
        QPoint(2, 8),
        QPoint(-2, 8),
        QPoint(-2, -60),
        QPoint(-3, -60),
        QPoint(-0, -70),
        QPoint(3, -60),
        QPoint(2, -60)
    };
    static const QPoint secondHand[7] = {
        QPoint(1, 12),
        QPoint(-1, 12),
        QPoint(-1, -40),
        QPoint(-2, -60),
        QPoint(-0, -80),
        QPoint(2, -60),
        QPoint(1, -40)
    };


    QColor colorHand(25,150,12,120);
    int side = qMin(width(), height());
    QTime time = QTime::currentTime();// time, the BIOS (current laptop)

    QPainter painter(this); //create painter
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2); //set (0;0)
    painter.scale(side / 325.0, side / 325.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(colorHand);

    painter.save();//connection of the hour hand with proofreader (change time zone)
    painter.rotate(30.0 * ((time.hour() + correctHour + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 7);
    painter.restore();

    painter.save();// connection of the minute hand with time
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 7);
    painter.restore();

    painter.save();// connection of the second hand with time
    painter.rotate(((time.second() * 1000.0) + time.msec()) * 0.006);
    painter.drawConvexPolygon(secondHand, 7);
    painter.restore();

    painter.setPen(Qt::NoBrush);
    painter.setBrush(colorHand);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 110, 0);
        painter.rotate(6.0);
    }

    for (int i = 0; i < 12; ++i) {
        painter.drawLine(80, 0, 96, 0);
        painter.rotate(30.0);
    }
}

void Clock::pressedBox(bool value)
{

    if (value)
    {
        correctHour = -4;
        comboBox->setCurrentIndex(zero);
        comboBox->show();
    }
    else
    {
        correctHour = 0;
        comboBox->hide();
    }
}

void Clock::timeZoneChanged(int index)
{
    correctHour = -4+index;
    comboBox->setCurrentIndex(index);
}
