#include "Counter.h"

Counter::Counter(QMutex *mutex, int *value)
{

    m_value = value;
    m_mutex = mutex;
}

void Counter::run()
{
    // We will wait until finished his job
    m_mutex->lock();

    QThread::currentThread()->msleep(10);
    *m_value = *m_value +1;
    qInfo()<<*m_value<<QThread::currentThread();

    m_mutex->unlock();
}
