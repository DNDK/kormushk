#ifndef KORMUSHKADB_H
#define KORMUSHKADB_H

#include <QSqlDatabase>
#include <QList>
#include "kormushka.h"

class KormushkaDB
{
public:
    KormushkaDB(QSqlDatabase* db);
    Kormushka* createKormushka(QString&, QString&, int&);
    Kormushka* editKormushka(int& id, QString& name, QString& type, int& status);
    bool deleteKormushka();
    Kormushka* getKormushka(int&);
    QList<Kormushka>* getKormushkas();

private:
    QSqlDatabase* db;
};

#endif // KORMUSHKADB_H
