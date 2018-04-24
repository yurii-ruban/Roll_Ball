#include "ball.h"

Ball::Ball()
{

}

int Ball::get_x()
{
    return x;
}

int Ball::get_y()
{
    return y;
}

int Ball::get_w()
{
    return w;
}

int Ball::get_h()
{
    return h;
}

void Ball::set_x(int _x)
{
    x=_x;
}

void Ball::set_y(int _y)
{
    y=_y;
}

void Ball::set_w(int _w)
{
    w=_w;
}

void Ball::set_h(int _h)
{
    h=_h;
}

void Ball::set_direct(int _direct)
{
    direct=_direct;
}
