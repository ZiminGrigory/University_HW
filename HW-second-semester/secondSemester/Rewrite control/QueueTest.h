#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "Queue.h"

class QueueTest:public QObject
{
    Q_OBJECT
public:
    explicit QueueTest(QObject *parent = 0):QObject(parent){}
private slots:
    void init()
    {
        queue = new Queue<int>();
    }

    void cleanup()
    {
        delete queue;
    }

    void testEnqueue()
    {
        queue->enqueu(25,4);
        queue->enqueu(1,4);
        queue->enqueu(2,8);
        queue->enqueu(3,2);
        queue->enqueu(4,5);
    }

    void testDequeueException()
    {
        try
        {
            queue->dequeue();
        }
        catch (Empty)
        {
            QCOMPARE(true,true);
        }
    }

    void testDequeue()
    {
        queue->enqueu(25,4);
        queue->enqueu(1,4);
        queue->enqueu(2,8);
        queue->enqueu(3,2);
        queue->enqueu(4,5);
        QCOMPARE(queue->dequeue(),2);
        QCOMPARE(queue->dequeue(),4);
    }

private:
    Queue<int> *queue;
};
QTEST_MAIN(QueueTest)
