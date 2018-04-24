#ifndef SAVER_H
#define SAVER_H


#include <QFile>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "someclass.h"

class Saver
{
public:
    Saver();
    void read_dataBase(SomeClass& S);
    void write_dataBase(SomeClass& S);
    void read_file(SomeClass& S);
    void write_file(SomeClass &S);
private:
    QFile file;
    QSqlDatabase db;
};

#endif // SAVER_H
