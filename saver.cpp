#include "saver.h"
#include <QString>
#include <QDebug>

Saver::Saver()
{

}

void Saver::read_dataBase(SomeClass& S)
{
    m_db =QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("Point");
    if(!m_db.isOpen())
    {
        if(m_db.open())
        {
            int x_;
            int y_;
            QSqlQuery query(m_db);
            query.exec("SELECT x, direct FROM ball WHERE id=1");

            while(query.next())
            {
                x_=query.value(0).toInt();
                y_=query.value(1).toInt();
                S.setter(x_,y_);
                qDebug()<<x_<<" "<<y_;
            }
        }
    }
    else
    {
        S.setter(20,1);
    }
}

void Saver::write_dataBase(SomeClass &S)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE ball SET x=:x, direct=:direct WHERE id=1");
    query.addBindValue(S.get_x());
    query.addBindValue(S.get_direct());
    query.exec();
}

void Saver::read_file(SomeClass& S)
{
    m_log.setm_logName("test.txt");
    if ((m_log.exists())&&(m_log.open(QIODevice::ReadOnly)))
    {
        QString a,b;
        QStringList strList;
        while(!m_log.atEnd())
        {
            strList << m_log.readLine();
        }
        m_log.close();
        bool OK;
        a= strList[0];
        b= strList[1];
        S.setter(a.toInt(&OK),b.toInt(&OK));
    }
}

void Saver::write_file(SomeClass& S)
{
    if (m_log.open(QIODevice::WriteOnly))
    {
        m_log.write((std::to_string(S.get_x())).c_str());
        m_log.write("\n");
        m_log.write((std::to_string(S.get_direct())).c_str());
        m_log.close();
    }
}
