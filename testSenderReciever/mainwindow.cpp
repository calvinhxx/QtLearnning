#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qt< 4.8
//    //信号和槽同形参
//    connect(this, SIGNAL(testSignalInt(int)), this, SLOT(testSlotInt(int)));
//    //信号与槽不同形参 信号有形参，槽无形参
//    connect(this, SIGNAL(testSignalInt(int)), this, SLOT(testSlotVoid()));
//    //信号与槽不同形参 信号无形参，槽需要参数  运行阶段报错
//    connect(this, SIGNAL(testSignalVoid()), this, SLOT(testSlotInt(int)));
    //qt< 5
//    connect(this, &MainWindow::testSignalInt, this, &MainWindow::testSlotInt);
//    connect(this, &MainWindow::testSignalInt, this, &MainWindow::testSlotVoid);
    //编译阶段报错
//    connect(this, &MainWindow::testSignalVoid, this, &MainWindow::testSlotInt);
    emit testSignalInt(4);
//    emit testSignalVoid();
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

