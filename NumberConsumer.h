#ifndef NUMBERCONSUMER_H
#define NUMBERCONSUMER_H


#include "NumberQueue.h"

class NumberConsumer : public QThread {
    Q_OBJECT

public:
    NumberConsumer(NumberQueue *queue, QObject *parent);

    void run() override;
    void startConsuming();
    void stopConsuming();
    int getConsumedNumber();

signals:
    void numberConsumed(int number);

private:
    NumberQueue *queue;
    bool running;
    QMutex mutex;
    int consumedNumber;
};


#endif // NUMBERCONSUMER_H
