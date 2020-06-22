#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moveToThreadTest.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    moveToThreadTest* obj = new moveToThreadTest(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

