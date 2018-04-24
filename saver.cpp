#include "saver.h"
#include <QString>
#include <QDebug>

Saver::Saver()
{

}

bool Saver::read_dataBase(Logic& S)
{
    m_db =QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("Point");
    if(!m_db.open())
    {
       S.setter(20,1);
       return 1;
    }
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
    return 1;
}

bool Saver::write_dataBase(Logic &S)
{
    if(!m_db.isValid())
    {
        return 0;
    }
    QSqlQuery query(m_db);
    query.prepare("UPDATE ball SET x=:x, direct=:direct WHERE id=1");
    query.addBindValue(S.get_ball().get_x());
    query.addBindValue(S.get_ball().get_direct());
    if(!query.exec())
    {
        return 0;
    }
    return 1;
}

bool Saver::read_file(Logic& S)
{
    m_log.setFileName("test.txt");
    if (!((m_log.exists())&&(m_log.open(QIODevice::ReadOnly))))
    {
        return 0;
    }
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
    return 1;
}

bool Saver::write_file(Logic& S)
{
    if (!(m_log.open(QIODevice::WriteOnly)))
    {
        return 0;
    }
    m_log.write((std::to_string(S.get_ball().get_x())).c_str());
    m_log.write("\n");
    m_log.write((std::to_string(S.get_ball().get_direct())).c_str());
    m_log.close();
    return 1;
}
