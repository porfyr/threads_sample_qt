// #include <QThread>
// #include <QMutex>
// #include <QWaitCondition>

// #include "numbergenerator.h"


// class NumberGenerator : public QThread {
//     Q_OBJECT

// public:
//     NumberGenerator(QObject *parent = nullptr) : QThread(parent), running(false), currentNumber(0) {}

//     void run() override {
//         while (running) {
//             QMutexLocker locker(&mutex);
//             currentNumber++;
//             emit numberGenerated(currentNumber);
//             QThread::msleep(1000);  // Sleep for 1 second
//         }
//     }

//     void startGenerating() {
//         QMutexLocker locker(&mutex);
//         running = true;
//         if (!isRunning()) start();
//     }

//     void stopGenerating() {
//         QMutexLocker locker(&mutex);
//         running = false;
//     }

// signals:
//     void numberGenerated(int number);

// private:
//     bool running;
//     int currentNumber;
//     QMutex mutex;
// };
