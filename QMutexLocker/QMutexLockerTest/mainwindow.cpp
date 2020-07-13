#include "mainwindow.h"
#include "ui_mainwindow.h"

QMutex CommonVar::mutex;
QString CommonVar::text;

void CommonVar::SetText(QString arg)
{
    QMutexLocker locker(&mutex);
    text = arg;
}
QString CommonVar::GetText()
{
    return text;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CommonVar::SetText("test");

    ui->label->setText(CommonVar::GetText());
}

MainWindow::~MainWindow()
{
    delete ui;
}

