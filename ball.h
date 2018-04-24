#ifndef BALL_H
#define BALL_H


class Ball
{
public:
    Ball();
    int get_x();
    int get_y();
    int get_w();
    int get_h();
    bool get_direct();
    void set_x(int _x);
    void set_y(int _y);
    void set_w(int _w);
    void set_h(int _h);
    void set_direct(bool _direct);

private:
    int x;
    int y;
    int w;
    int h;
    bool direct;
};

#endif // BALL_H
