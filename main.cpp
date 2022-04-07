#include <QCoreApplication>
#include "Counter.h"
#include <QThread>
#include <QDebug>
#include <QThreadPool>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QThread::currentThread()->setObjectName("Main");

    QThreadPool * pool = QThreadPool::globalInstance();

    QMutex mutex;
    int value = 0;
    qInfo()<<pool->maxThreadCount();
    for(int i=0; i< 100;i++)
    {
        Counter *c =new Counter(&mutex,&value);
        c->setAutoDelete(true);
        pool->start(c);
    }

    return a.exec();
}
