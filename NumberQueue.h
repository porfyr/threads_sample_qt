#ifndef NUMBERQUEUE_H
#define NUMBERQUEUE_H

#include <queue>
#include <QThread>
#include <QMutex>

class NumberQueue : public QThread {
    Q_OBJECT

public:
    NumberQueue(QObject *parent = nullptr) : QThread(parent) {}

    void addNumber(int number);

    std::vector<int> getQueue();

    int getNextNumber();

signals:
    void queueUpdated();

private:
    std::queue<int> queue;
    QMutex mutex;
};


#endif // NUMBERQUEUE_H
