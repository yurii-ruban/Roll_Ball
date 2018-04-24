#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (&m_thread1,&QThread::started, &m_counter, &Logic::run);
    connect (&m_counter,&Logic::sendData, &m_drawer, &Logic::setter);
    connect(&m_counter, &Logic::finished, &m_thread1, &QThread::quit, Qt::DirectConnection);
    connect(&m_counter, &Logic::finished, &m_thread2, &QThread::quit, Qt::DirectConnection);
    connect(this, &MainWindow::end, &m_counter, &Logic::finish);

    m_counter.moveToThread(&m_thread1);
    m_drawer.moveToThread(&m_thread2);

    if(!(m_manager.read_dataBase(m_counter)))
    {
        qDebug()<<"DATA WASN'T READED";
    }

    m_drawer.setter(m_counter.get_ball().get_x(), m_counter.get_ball().get_direct());
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black,2,Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(Qt::green);
    painter.drawEllipse(m_drawer.get_ball().get_x(),m_drawer.get_ball().get_y(),m_drawer.get_ball().get_w(),m_drawer.get_ball().get_h());
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
    if(!(m_manager.write_dataBase(m_counter)))
    {
     qDebug()<<"DATA WASN'T SAVED";
    }
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
