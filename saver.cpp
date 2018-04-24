#include "saver.h"
#include <QString>
#include <QDebug>

Saver::Saver()
{

}

void Saver::read_dataBase(SomeClass& S)
{
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Point");
    if(!db.isOpen())
    {
        if(db.open())
        {
            int x_;
            int y_;
            QSqlQuery query(db);
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
    QSqlQuery query(db);
    query.prepare("UPDATE ball SET x=:x, direct=:direct WHERE id=1");
    query.addBindValue(S.get_x());
    query.addBindValue(S.get_direct());
    query.exec();
}

void Saver::read_file(SomeClass& S)
{
    file.setFileName("test.txt");
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QString a,b;
        QStringList strList;
        while(!file.atEnd())
        {
            strList << file.readLine();
        }
        file.close();
        bool OK;
        a= strList[0];
        b= strList[1];
        S.setter(a.toInt(&OK),b.toInt(&OK));
    }
}

void Saver::write_file(SomeClass& S)
{
    if (file.open(QIODevice::WriteOnly))
    {
        file.write((std::to_string(S.get_x())).c_str());
        file.write("\n");
        file.write((std::to_string(S.get_direct())).c_str());
        file.close();
    }
}
