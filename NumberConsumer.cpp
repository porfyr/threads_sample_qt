#include "NumberConsumer.h"
#include <QMutexLocker>

// NumberConsumer::NumberConsumer(NumberQueue *queue, QObject *parent) : QThread(parent), queue(queue), running(false) {}

void NumberConsumer::run() {
    while (running) {
        int number = queue->getNextNumber();
        if (number != -1) {
            emit numberConsumed(number);
            QThread::msleep(1000);  // 1 second delay
        }
    }
}

void NumberConsumer::startConsuming() {
    QMutexLocker locker(&mutex);
    running = true;
    if (!isRunning()) start();
}

void NumberConsumer::stopConsuming() {
    QMutexLocker locker(&mutex);
    running = false;
}
