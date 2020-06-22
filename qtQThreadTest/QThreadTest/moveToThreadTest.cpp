#include "moveToThreadTest.h"
#include <QDebug>

Worker::Worker(QObject *parent) : QObject(parent)
{
    qDebug() << "Worker" << QThread::currentThread();
}
void Worker::function()
{
    qDebug() << "function" << QThread::currentThread();
}
Worker::~Worker()
{
    qDebug() << "Worker del" << QThread::currentThread();
}
void Worker::doWork( QString test)
{
    emit resultReady();
    qDebug() << "doWork" << QThread::currentThread();
    function();
}

moveToThreadTest::moveToThreadTest(QObject *parent) : QObject(parent)
{
    Worker *worker = new Worker();
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, SIGNAL( operate(QString) ), worker, SLOT( doWork(QString) ));
    connect(worker, SIGNAL( resultReady() ), this, SLOT( handleResults() ));
    workerThread.start();
    emit operate("test");
}
void moveToThreadTest::handleResults()
{
    qDebug() << "handleResults" << QThread::currentThread();
}
moveToThreadTest::~moveToThreadTest()
{
    workerThread.quit();
    workerThread.wait();
}
