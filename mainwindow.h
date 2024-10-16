#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QTimer>

#include "NumberGenerator.h"
#include "NumberQueue.h"
#include "NumberConsumer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *refreshTimer;

    NumberGenerator *generatorThread;
    NumberQueue *queueThread;
    NumberConsumer *consumerThread;

    bool isGeneratorRunning = false;
    bool isConsumerRunning = false;

private slots:
    void updateLists();
    void toggleThread1();
    void toggleThread3();
};
#endif // MAINWINDOW_H
