#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include <string>
#include <QSqlDatabase>
#include <QList>

class Admin
{
public:
    Admin(QSqlDatabase* db);
    ~Admin();
    User* addUser(QString& username, QString& password, QString& role);
    User* editUser(int& id, QString& username, QString& password, QString& role);
    bool deleteUser(int&);
    QList<User>* getUsers();
    User* getUser(int&);
    User* getUser(QString&, QString&);


private:
    QSqlDatabase* db;
    void createTable();
};

#endif // ADMIN_H
