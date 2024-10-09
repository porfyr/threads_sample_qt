#include "NumberGenerator.h"
#include <QMutexLocker>

// NumberGenerator::NumberGenerator(QObject *parent) : QThread(parent), running(false), currentNumber(0) {}

void NumberGenerator::run() {
    while (running) {
        QMutexLocker locker(&mutex);
        currentNumber++;
        emit numberGenerated(currentNumber);
        QThread::msleep(1000);  // 1 second delay between number generation
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
