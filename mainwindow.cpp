#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->button_1, &QPushButton::clicked, this, &MainWindow::toggleThread1);
    connect(ui->button_3, &QPushButton::clicked, this, &MainWindow::toggleThread3);

    refreshTimer = new QTimer(this);
    connect(refreshTimer, &QTimer::timeout, this, &MainWindow::updateLists);
    refreshTimer->start(333);
}

void MainWindow::toggleThread1() {
    // Start/Stop logic for Thread 1 (Number generator)
    qDebug() << "toggle 1";
}

void MainWindow::toggleThread3() {
    // Start/Stop logic for Thread 3 (Number consumer)
    qDebug() << "toggle 3";
}

void MainWindow::updateLists() {
    // Refresh the list widgets with the latest data from the threads
    qDebug() << "update lists";

}

MainWindow::~MainWindow()
{
    delete ui;
}
