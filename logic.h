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
    Ball m_bouncy;
    QTimer *m_timer;

public:
    explicit Logic(QObject *parent = nullptr);
    ~Logic();
    Ball get_ball();
    void move();
signals:
    void finished();
    void sendData(int x, bool direct);

public slots:
    void run();
    void setter(int x, bool direct);
    void finish();
};

#endif // Logic_H
