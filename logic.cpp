#include "logic.h"

Logic::Logic(QObject *parent) : QObject(parent)
{
    bouncy.set_y(200);
    bouncy.set_w(100);
    bouncy.set_h(100);
}

Logic::~Logic()
{
    delete spy;
}

void Logic::set_ball(Ball &_bouncy)
{
    this->bouncy=_bouncy;
}

Ball Logic::get_ball()
{
    return bouncy;
}

void Logic::move()
{
    if(bouncy.get_x()>=596)
    {
        bouncy.set_direct(0);
    }
    else if  (bouncy.get_x()<=4)
    {
        bouncy.set_direct(1);
    }

    int x=bouncy.get_x();
    switch (bouncy.get_direct())
    {
    case 0:
        bouncy.set_x(--x);
        break;
    case 1:
        bouncy.set_x(++x);
        break;
    }

    emit sendData(bouncy.get_x(), bouncy.get_direct());
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
    this->bouncy.set_x(x);
    this->bouncy.set_direct(direct);
}

void Logic::finish()
{
    m_timer->stop();
    delete m_timer;
    Q_ASSERT(spy->count()==1);
    emit finished();
}
