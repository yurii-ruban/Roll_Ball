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
    bool read_dataBase(Logic& S);
    bool write_dataBase(Logic &S);
    bool read_file(Logic& S);
    bool write_file(Logic& S);
private:
    QFile m_log;
    QSqlDatabase m_db;
};

#endif // SAVER_H
