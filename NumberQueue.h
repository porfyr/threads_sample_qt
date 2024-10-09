#ifndef NUMBERQUEUE_H
#define NUMBERQUEUE_H

#include <queue>
#include <QThread>
#include <QMutex>

class NumberQueue : public QThread {
    Q_OBJECT

public:
    NumberQueue(QObject *parent = nullptr) : QThread(parent) {}

    void addNumber(int number) {
        QMutexLocker locker(&mutex);
        if (queue.size() >= 20) {
            queue.pop();  // Remove the oldest number
        }
        queue.push(number);
        emit queueUpdated();
    }

    int getNextNumber() {
        QMutexLocker locker(&mutex);
        if (queue.empty()) return -1;
        int number = queue.front();
        queue.pop();
        return number;
    }

signals:
    void queueUpdated();

private:
    std::queue<int> queue;
    QMutex mutex;
};


#endif // NUMBERQUEUE_H
