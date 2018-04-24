#include "logic.h"

Logic::Logic(QObject *parent) : QObject(parent)
{
    y=200;
    w=100;
    h=100;
}

Logic::~Logic()
{
    //QSignalSpy spy(m_timer, SIGNAL(destroyed(QObject*)));
//    QEXPECT_FAIL("", "Will fix in the next release", Continue);
//    QCOMPARE(spy.count(), 2);
    //QVERIFY(spy.count()==0);
    delete spy;
}

int Logic::get_x()
{
    return x;
}

int Logic::get_y()
{
    return y;
}

int Logic::get_w()
{
    return w;
}

int Logic::get_h()
{
    return h;
}

int Logic::get_direct()
{
    return direct;
}


void Logic::move()
{
    if(x>=596)
    {
        direct=0;
    }
    else if  (x<=4)
    {
        direct=1;
    }

    switch (direct)
    {
    case 0:
        x--;
        break;
    case 1:
        x++;
        break;
    }

    emit sendData(x, direct);
}

void Logic::run()
{
    m_timer= new QTimer(this);
    spy= new QSignalSpy(m_timer, SIGNAL(destroyed(QObject*)));
    connect(m_timer, &QTimer::timeout, this, &Logic::move);
    m_timer->setInterval(2);
    m_timer->start();


}

void Logic::setter(int x, int direct)
{
    this->x=x;
    this->direct=direct;
}

void Logic::finish()
{
    m_timer->stop();
    delete m_timer;
    Q_ASSERT(spy->count()==1);
    emit finished();
}
