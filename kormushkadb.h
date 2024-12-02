#ifndef KORMUSHKADB_H
#define KORMUSHKADB_H

#include <QSqlDatabase>
#include <QList>
#include "kormushka.h"

class KormushkaDB
{
public:
    KormushkaDB(QSqlDatabase* db);
    Kormushka* createKormushka();
    Kormushka* editKormushka();
    bool deleteKormushka();
    Kormushka* getKormushka(int&);
    QList<Kormushka>* getKormushkas();

private:
    QSqlDatabase* db;
};

#endif // KORMUSHKADB_H
