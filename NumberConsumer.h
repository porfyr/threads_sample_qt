#ifndef NUMBERCONSUMER_H
#define NUMBERCONSUMER_H

// #include <QThread>
// #include <QMutex>
// #include <QWaitCondition>

#include "NumberQueue.h"

class NumberConsumer : public QThread {
    Q_OBJECT

public:
    NumberConsumer(NumberQueue *queue, QObject *parent = nullptr) : QThread(parent), queue(queue), running(false) {}

    void run() override {
        while (running) {
            int number = queue->getNextNumber();
            if (number != -1) {
                emit numberConsumed(number);
                QThread::msleep(1000);  // Sleep for 1 second
            }
        }
    }

    void startConsuming() {
        QMutexLocker locker(&mutex);
        running = true;
        if (!isRunning()) start();
    }

    void stopConsuming() {
        QMutexLocker locker(&mutex);
        running = false;
    }

signals:
    void numberConsumed(int number);

private:
    NumberQueue *queue;
    bool running;
    QMutex mutex;
};


#endif // NUMBERCONSUMER_H
