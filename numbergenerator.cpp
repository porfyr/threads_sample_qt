#include <QMutexLocker>

#include "NumberGenerator.h"
#include "defs.h"

NumberGenerator::NumberGenerator(QObject *parent)
    : QThread(parent), running(false), currentNumber(0) {}

void NumberGenerator::run() {
    // qDebug() << "started NumberGenerator::run()";
    while (running) {
        QMutexLocker locker(&mutex);
        currentNumber++;
        locker.unlock();
        emit numberGenerated(currentNumber);
        QThread::msleep(UPDATE_PERIOD);
    }
}

void NumberGenerator::startGenerating() {
    QMutexLocker locker(&mutex);
    running = true;
    if (!isRunning()) start();
}

void NumberGenerator::stopGenerating() {
    QMutexLocker locker(&mutex);
    running = false;
}

int NumberGenerator::getCurrentNumber() {
    QMutexLocker locker(&mutex);
    return currentNumber;
}
