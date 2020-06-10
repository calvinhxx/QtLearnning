#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

//信号与槽函数在同一线程
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 5; i++)
    {//采用默认方式，连接5次
        connect(this, SIGNAL(sigFirst()), this, SLOT(slotFirst()));
//        connect(this, SIGNAL(sigFirst()), this, SLOT(slotFirst()),Qt::UniqueConnection);
    }
    emit sigFirst();
}
void MainWindow::slotFirst()
{
    numCoon++;
    qDebug() << QStringLiteral("信号第")<<numCoon<<QStringLiteral("次连接");
}
MainWindow::~MainWindow()
{
    delete ui;
}

