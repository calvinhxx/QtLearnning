#include "Test.h"
#include "QtTestThread.h"
#include <QDebug>

Test::Test(QWidget *parent) : QMainWindow(parent)
{
    testThread = new QtTestThread(this);
    //没有第五个参数，也就是采用默认的连接方式,即QueuedConnection
//    connect(testThread, SIGNAL(sigSecond()), this, SLOT(slotThread()));
    //
    connect(testThread, SIGNAL(sigSecond()), this, SLOT(slotThread()),Qt::BlockingQueuedConnection);
    testThread->start();
}
void Test::slotThread()
{
    qDebug() << QStringLiteral("线程发送的信号-槽函数执行！");
    QThread::sleep(3);
}
