#include "admin.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QDebug>
#include <iostream>
Admin::Admin(const QString& dbName) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if(!db.open()){
        qDebug() << "Я люблю грязный пенис, черный пенис...";
    }
    createTable();
}

Admin::~Admin(){
    db.close();
}

User* Admin::addUser(QString& username, QString& password, QString& role) {
    QSqlQuery createQuery;
    createQuery.prepare("INSERT INTO Users(username, password, role) VALUES (:username, :password, :role);");
    createQuery.bindValue(":username", QVariant(username));
    createQuery.bindValue(":password", QVariant(password));
    createQuery.bindValue(":role", QVariant(role));

    if (!createQuery.exec()) {
        qDebug() << "Ошибка при добавлении пользователя:" << createQuery.lastError().text();
        return nullptr;
    }

    // Получаем последний вставленный id
    int newId = createQuery.lastInsertId().toInt(); // Преобразуем в int

    // Создаем нового пользователя с полученным id
    User* newUser = new User(newId, username, password, role); // Предполагается, что конструктор User принимает id
    return newUser;
}

User* Admin::editUser(int& id, QString& username, QString& password, QString& role){
    QSqlQuery editQuery;
    editQuery.prepare("UPDATE Users SET username=:username, password=:password, role=:role WHERE id=:id");
    editQuery.bindValue(":username", username);
    editQuery.bindValue(":password", password);
    editQuery.bindValue(":role", role);
    editQuery.bindValue(":id", id);

    if(!editQuery.exec()){
        qDebug() << "Саси мне оу ес саси саси саси";
        return nullptr;
    }

    User* edittedUser = new User(id, username, password, role);
    return edittedUser;
}

bool Admin::deleteUser(int& id){
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Users WHERE id=:id");
    deleteQuery.bindValue(":id", id);
    return deleteQuery.exec();
}


User* Admin::getUser(int& id){
    QSqlQuery getQuery("SELECT * FROM Users WHERE id=:id");
    getQuery.bindValue(":id", QVariant(id));
    User* user = nullptr;
    if(getQuery.next()){
        qDebug() << "Pablo found";
        int id = getQuery.value(0).toInt();
        QString username = getQuery.value(1).toString();

        QString password = getQuery.value(2).toString();
        QString role     = getQuery.value(3).toString();

        user = new User(id, username, password, role); // 8====D - - -. . -.
    }
    return user;
}


User* Admin::getUser(QString& username, QString& password){
    QSqlQuery getQuery;
    getQuery.exec("SELECT id, username, password, role FROM Users WHERE username='" + username + "' AND password='" + password + "'");
    if(getQuery.first()){
        int id = getQuery.value(0).toInt();
        QString receivedUsername = getQuery.value(1).toString();
        QString receivedPassword = getQuery.value(2).toString();
        QString receivedRole     = getQuery.value(3).toString();
        User* user = new User(id, receivedUsername, receivedPassword, receivedRole);
        return user; // 8====D - - -. . -.
    }
    return nullptr;
}

void Admin::createTable(){
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS Users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT NOT NULL, password TEXT NOT NULL, role TEXT NOT NULL);");
}

QList<User>* Admin::getUsers(){
    QSqlQuery query;
    query.exec("select id, username, password, role from users");
    QList<User>* users = new QList<User>();
    while(query.next()){
        int id           = query.value(0).toInt();
        QString username = query.value(1).toString();
        QString password = query.value(2).toString();
        QString role     = query.value(3).toString();
        User currentUser(id, username, password, role);
        users->push_back(currentUser);
    }
    return users;
}
