#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "defs.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    generatorThread = new NumberGenerator(this);
    queueThread = new NumberQueue(this);
    consumerThread = new NumberConsumer(queueThread, this);

    connect(generatorThread, &NumberGenerator::numberGenerated, queueThread, &NumberQueue::addNumber);
    connect(queueThread, &NumberQueue::queueUpdated, this, &MainWindow::updateLists);
    connect(consumerThread, &NumberConsumer::numberConsumed, this, &MainWindow::updateLists);

    connect(ui->button_1, &QPushButton::clicked, this, &MainWindow::toggleThread1);
    connect(ui->button_3, &QPushButton::clicked, this, &MainWindow::toggleThread3);

    refreshTimer = new QTimer(this);
    connect(refreshTimer, &QTimer::timeout, this, &MainWindow::updateLists);
    refreshTimer->start(UPDATE_PERIOD);
}

void MainWindow::toggleThread1() {
    qDebug() << "pressed toggle thread 1";
    if (isGeneratorRunning) {
        generatorThread->stopGenerating();
        ui->button_1->setText("Start thread 1");
    } else {
        // qDebug() << "gen isn't running";
        generatorThread->startGenerating();
        ui->button_1->setText("Stop thread 1");
    }
    isGeneratorRunning = !isGeneratorRunning;
}

void MainWindow::toggleThread3() {
    qDebug() << "pressed toggle thread 3";
    if (isConsumerRunning) {
        consumerThread->stopConsuming();
        ui->button_3->setText("Start thread 3");
    } else {
        consumerThread->startConsuming();
        ui->button_3->setText("Stop thread 3");
    }
    isConsumerRunning = !isConsumerRunning;
}

void MainWindow::updateLists() {
    // Update the list widgets with numbers from each thread
    ui->listWidget_1->clear();
    ui->listWidget_2->clear();
    ui->listWidget_3->clear();

    // Add numbers from generator and queue to the lists
    ui->listWidget_1->addItem(QString::number(generatorThread->getCurrentNumber()));
    std::vector<int> queue = queueThread->getQueue();
    for (auto &queue_num : queue) {
        ui->listWidget_2->addItem(QString::number(queue_num));
    }
    int consumedNumber = consumerThread->getConsumedNumber();
    if (consumedNumber != -1)
        ui->listWidget_3->addItem(QString::number(consumedNumber));
    qDebug() << "ui list updated";
}

MainWindow::~MainWindow()
{
    delete ui;
}
