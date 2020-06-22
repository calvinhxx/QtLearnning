#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
class QtTestThread;
class Test : public QMainWindow
{
    Q_OBJECT
public:
    explicit Test(QWidget *parent = nullptr);

signals:
    void sigFirst();
private slots:
    void slotThread();
private:
    QtTestThread* testThread;
};

#endif // TEST_H
