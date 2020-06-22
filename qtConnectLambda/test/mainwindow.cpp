#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
void testfuntor()
{
    qDebug() << "testfuntor";
}
//#1.信号槽取消绑定的时机 //sender|reciever|handler destory connection
//#2.信号槽当中lambda的声明周期取决于context
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton* push = new QPushButton(this);
    push->setText("testpush");

//    connect(ui->pushButton, &QPushButton::clicked, this, testfuntor);
    //    //程序不down
    //    connect(ui->pushButton, &QPushButton::clicked, push, [=](){
    //            qDebug() << push->text();
    //    });
    //    delete push;
    //程序down 因为lambda还存活但是没disconnect, 但是push内存已经被释放
    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
            qDebug() << push->text();
    });
    delete push;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TestFuntor()
{
    qDebug() << "functor";
}
