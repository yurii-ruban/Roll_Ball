#include "logic.h"

Logic::Logic(QObject *parent) : QObject(parent)
{
    m_bouncy.set_y(200);
    m_bouncy.set_w(100);
    m_bouncy.set_h(100);
}

Logic::~Logic()
{
}

Ball Logic::get_ball()
{
    return m_bouncy;
}

void Logic::move()
{
    int x=m_bouncy.get_x();
    if(m_bouncy.get_x()>=596)
    {
        m_bouncy.set_direct(1);
    }
    else if  (m_bouncy.get_x()<=4)
    {
        m_bouncy.set_direct(0);
    }

    switch (m_bouncy.get_direct())
    {
    case 0:
        m_bouncy.set_x(++x);
        break;
    case 1:
        m_bouncy.set_x(--x);
        break;
    }

    emit sendData(m_bouncy.get_x(), m_bouncy.get_direct());
}

void Logic::run()
{
    m_timer= new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Logic::move);
    m_timer->setInterval(2);
    m_timer->start();


}

void Logic::setter(int x, bool direct)
{
    this->m_bouncy.set_x(x);
    this->m_bouncy.set_direct(direct);
}

void Logic::finish()
{
    m_timer->stop();
    delete m_timer;
    emit finished();
}
