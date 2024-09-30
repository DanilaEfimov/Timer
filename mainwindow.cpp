#include "mainwindow.h"
#include "ui_mainwindow.h"

Counter* MainWindow::timer = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(timer);
}

MainWindow::~MainWindow()
{
    delete ui;
}
