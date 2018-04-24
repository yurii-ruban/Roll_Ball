#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (&m_thread1,&QThread::started, &m_some1, &Logic::run);
    connect (&m_some1,&Logic::sendData, &m_some2, &Logic::setter);
    connect(&m_some1, &Logic::finished, &m_thread1, &QThread::quit, Qt::DirectConnection);
    connect(&m_some1, &Logic::finished, &m_thread2, &QThread::quit, Qt::DirectConnection);
    connect(this, &MainWindow::end, &m_some1, &Logic::finish);

    m_some1.moveToThread(&m_thread1);
    m_some2.moveToThread(&m_thread2);

    m_manager.read_dataBase(m_some1);
    m_some2.setter(m_some1.get_x(), m_some1.get_direct());
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black,2,Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(Qt::cyan);
    painter.drawEllipse(m_some2.get_x(),m_some2.get_y(),m_some2.get_w(),m_some2.get_h());
    update();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(m_thread1.isRunning())
    {
        emit end();
    }
}

MainWindow::~MainWindow()
{
    m_manager.write_dataBase(m_some1);
    delete ui;
}

void MainWindow::on_Go_clicked()
{
    m_thread1.start();
    m_thread2.start();
}

void MainWindow::on_Stop_clicked()
{
    if(m_thread1.isRunning())
    {
        emit end();
    }
}
