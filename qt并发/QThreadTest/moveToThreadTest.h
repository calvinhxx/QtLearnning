#ifndef MOVETOTHREADTEST_H
#define MOVETOTHREADTEST_H

#include <QObject>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();
    void function();
signals:
    void resultReady();
public slots:
    void doWork(QString);
};

class moveToThreadTest : public QObject
{
    Q_OBJECT
public:
    explicit moveToThreadTest(QObject *parent = nullptr);
    ~moveToThreadTest();
signals:
    void operate(QString);
private slots:
    void handleResults();
private:
    QThread workerThread;
};

#endif // MOVETOTHREADTEST_H
