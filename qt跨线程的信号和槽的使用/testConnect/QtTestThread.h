#ifndef QTTESTTHREAD_H
#define QTTESTTHREAD_H

#pragma once

#include <QThread>

class QtTestThread : public QThread
{
    Q_OBJECT
public:
    explicit QtTestThread(QObject *parent = nullptr);

signals:
protected:
    void run();
signals:
    void sigSecond();
};

#endif // QTTESTTHREAD_H
