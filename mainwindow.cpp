#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>

Counter* MainWindow::timer = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new Counter(this);
    this->setCentralWidget(timer);

    this->setWindowTitle("Timer");
    this->setPalette(palette);
    this->setWindowIcon(QIcon("E:/Qt creator/Timer/src/images/timer.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}
