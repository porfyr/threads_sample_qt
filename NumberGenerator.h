#ifndef NUMBERGENERATOR_H
#define NUMBERGENERATOR_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>


class NumberGenerator : public QThread {
    Q_OBJECT

public:
    NumberGenerator(QObject *parent);

    // void run() override;

    // void startGenerating();

    // void stopGenerating();

    // int getCurrentNumber();

public slots:
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
