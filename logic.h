#ifndef Logic_H
#define Logic_H

#include <QObject>
#include <QTimer>
#include <QSignalSpy>
#include <QTest>
#include "ball.h"

class Logic : public QObject
{
    Q_OBJECT

private:
    Ball bouncy;
    QTimer *m_timer;
    QSignalSpy *spy;

public:
    explicit Logic(QObject *parent = nullptr);
    ~Logic();
    void set_ball(Ball& _bouncy);
    Ball get_ball();
    void move();
signals:
    void finished();
    void sendData(int x, int direct);

public slots:
    void run();
    void setter(int x, int direct);
    void finish();
};

#endif // Logic_H
