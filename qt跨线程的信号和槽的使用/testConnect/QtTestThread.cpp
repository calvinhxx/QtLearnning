#include "QtTestThread.h"
#include <QDebug>

QtTestThread::QtTestThread(QObject *parent) : QThread(parent)
{

}
void QtTestThread::run()
{
    emit sigSecond();
    qDebug() << QStringLiteral("信号发送完毕!");
}
