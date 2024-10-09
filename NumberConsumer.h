#ifndef NUMBERCONSUMER_H
#define NUMBERCONSUMER_H

#include "NumberQueue.h"

class NumberConsumer : public QThread {
    Q_OBJECT

public:
    NumberConsumer(NumberQueue *queue, QObject *parent = nullptr) : QThread(parent), queue(queue), running(false) {}

    void run() override;

    void startConsuming();

    void stopConsuming();
signals:
    void numberConsumed(int number);

private:
    NumberQueue *queue;
    bool running;
    QMutex mutex;
};


#endif // NUMBERCONSUMER_H
