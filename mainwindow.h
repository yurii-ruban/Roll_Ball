#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QThread>
#include <QCloseEvent>
#include "logic.h"
#include "saver.h"

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
    Logic m_counter;
    Logic m_drawer;
    Saver m_manager;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
