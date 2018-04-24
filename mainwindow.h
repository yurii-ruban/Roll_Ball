#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QThread>
#include <QCloseEvent>
#include "someclass.h"
#include "saver.h"
#include <QSignalSpy>
#include <QTest>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);
    void closeEvent (QCloseEvent *event);

signals:
    void end();

private slots:
    void on_Go_clicked();
    void on_Stop_clicked();

private:
    QThread m_thread1;
    QThread m_thread2;
    SomeClass m_some1;
    SomeClass m_some2;
    Saver m_manager;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
