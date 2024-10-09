#ifndef NUMBERGENERATOR_H
#define NUMBERGENERATOR_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class NumberGenerator : public QThread {
    Q_OBJECT

public:
    NumberGenerator(QObject *parent = nullptr) : QThread(parent), running(false), currentNumber(0) {}

    void run() override;

    void startGenerating();

    void stopGenerating();

    int getCurrentNumber();

signals:
    void numberGenerated(int number);

private:
    bool running;
    int currentNumber;
    QMutex mutex;
};


#endif // NUMBERGENERATOR_H
