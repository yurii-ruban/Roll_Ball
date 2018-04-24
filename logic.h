#ifndef Logic_H
#define Logic_H

#include <QObject>
#include <QTimer>
#include <QSignalSpy>
#include <QTest>

class Logic : public QObject
{
    Q_OBJECT

private:
    int x;
    int y;
    int w;
    int h;
    int direct;
    QTimer *m_timer;
    QSignalSpy *spy;

public:
    explicit Logic(QObject *parent = nullptr);
    ~Logic();
    int get_x();
    int get_y();
    int get_w();
    int get_h();
    int get_direct();
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
