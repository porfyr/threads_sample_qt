#include "NumberConsumer.h"
#include <QMutexLocker>

#include "defs.h"

NumberConsumer::NumberConsumer(NumberQueue *queue, QObject *parent)
    : QThread(parent), queue(queue), running(false), consumedNumber(-1) {}

void NumberConsumer::run() {
    while (running) {
        int number = queue->getNextNumber();
        if (number != -1) {
            consumedNumber = number;
            emit numberConsumed(number);
            QThread::msleep(UPDATE_PERIOD);
        }
    }
}

void NumberConsumer::startConsuming() {
    QMutexLocker locker(&mutex);
    running = true;
    locker.unlock();
    if (!isRunning()) start();
}

void NumberConsumer::stopConsuming() {
    QMutexLocker locker(&mutex);
    running = false;
}


int NumberConsumer::getConsumedNumber() {
    return consumedNumber;
}
