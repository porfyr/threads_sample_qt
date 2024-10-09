#include "NumberQueue.h"

// NumberQueue::NumberQueue(QObject *parent) : QThread(parent) {}

void NumberQueue::addNumber(int number) {
    QMutexLocker locker(&mutex);
    if (queue.size() >= 20) {
        queue.pop();  // Remove the oldest number
    }
    queue.push(number);
    emit queueUpdated();
}

std::vector<int> NumberQueue::getQueue() {
    QMutexLocker locker(&mutex);
    std::vector<int> qVector;
    std::queue<int> copyQueue = queue;

    while (!copyQueue.empty()) {
        qVector.push_back(copyQueue.front());
        copyQueue.pop();
    }

    return qVector;
}

int NumberQueue::getNextNumber() {
    QMutexLocker locker(&mutex);
    if (queue.empty()) return -1;
    int number = queue.front();
    queue.pop();

    return number;
}
