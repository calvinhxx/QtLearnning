#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //信号和槽同形参
    connect(this, SIGNAL(testSignalInt(int)), this, SLOT(testSlotInt(int)));
    //信号与槽不同形参 信号有形参，槽无形参
    connect(this, SIGNAL(testSignalInt(int)), this, SLOT(testSlotVoid()));
    //信号与槽不同形参 信号无形参，槽需要参数  错误不能使用
    connect(this, SIGNAL(testSignalVoid()), this, SLOT(testSlotInt(int)));
//    emit testSignalInt(4);
    emit testSignalVoid();
}
void MainWindow::testSlotVoid()
{
    qDebug() << "testSlotVoid";
}
void MainWindow::testSlotInt(int value)
{
    qDebug() << "testSlot" << value;
}

MainWindow::~MainWindow()
{
    delete ui;
}

