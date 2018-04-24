#ifndef SAVER_H
#define SAVER_H


#include <QFile>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "logic.h"

class Saver
{
public:
    Saver();
    void read_dataBase(Logic& S);
    void write_dataBase(Logic& S);
    void read_file(Logic& S);
    void write_file(Logic &S);
private:
    QFile m_log;
    QSqlDatabase m_db;
};

#endif // SAVER_H
