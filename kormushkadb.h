#ifndef KORMUSHKADB_H
#define KORMUSHKADB_H

#include <QSqlDatabase>
#include <QList>
#include "kormushka.h"

class KormushkaDB
{
public:
    KormushkaDB(QSqlDatabase* db);
    Kormushka* createKormushka(QString&, QString&, int&, int&);
    Kormushka* editKormushka(int& id, QString& name, QString& type, int& status, int& ownerId);
    bool deleteKormushka(int&);
    Kormushka* getKormushka(int&);
    QList<Kormushka>* getKormushkas();
    QList<Kormushka>* getKormushkas(int& userId);

private:
    QSqlDatabase* db;
    void createTable();
};

#endif // KORMUSHKADB_H
