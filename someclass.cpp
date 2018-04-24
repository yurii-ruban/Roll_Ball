#include "someclass.h"

SomeClass::SomeClass(QObject *parent) : QObject(parent)
{
    y=200;
    w=100;
    h=100;
}

SomeClass::~SomeClass()
{
    //QSignalSpy spy(m_timer, SIGNAL(destroyed(QObject*)));
//    QEXPECT_FAIL("", "Will fix in the next release", Continue);
//    QCOMPARE(spy.count(), 2);
    //QVERIFY(spy.count()==0);
}

int SomeClass::get_x()
{
    return x;
}

int SomeClass::get_y()
{
    return y;
}

int SomeClass::get_w()
{
    return w;
}

int SomeClass::get_h()
{
    return h;
}

int SomeClass::get_direct()
{
    return direct;
}


void SomeClass::move()
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

void SomeClass::run()
{
    m_timer= new QTimer(this);
    spy= new QSignalSpy(m_timer, SIGNAL(destroyed(QObject*)));
    connect(m_timer, &QTimer::timeout, this, &SomeClass::move);
    m_timer->setInterval(2);
    m_timer->start();


}

void SomeClass::setter(int x, int direct)
{
    this->x=x;
    this->direct=direct;
}

void SomeClass::finish()
{
    Q_ASSERT(spy->count()==0);
    m_timer->stop();
    delete m_timer;
    emit finished();
}
