#include <QDebug>
#include "kormushkadb.h"
#include "kormushka.h"
#include <QSqlQuery>
#include <QSqlError>

KormushkaDB::KormushkaDB(QSqlDatabase* db) {
    this->db = db;
    createTable();
}

void KormushkaDB::createTable(){
    QSqlQuery createTableQuery;
    createTableQuery.exec("CREATE TABLE IF NOT EXISTS "
                          "Kormushkas ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "name TEXT NOT NULL, "
                          "type TEXT NOT NULL, "
                          "status INTEGER, "
                          "FOREIGN KEY (owner_id) REFERENCES Users (id));");
}

Kormushka* KormushkaDB::createKormushka(QString& name, QString& type, int& status, int& ownerId){
    qDebug() << QVariant(name) << " " << QVariant(type) << " " << QVariant(status);

    QSqlQuery createQuery;
    createQuery.prepare("INSERT INTO Kormushkas(name, type, status, owner_id) VALUES (:name, :type, :status, :onwerId);");
    createQuery.bindValue(":name", QVariant(name));
    createQuery.bindValue(":type", QVariant(type));
    createQuery.bindValue(":status", QVariant(status));
    createQuery.bindValue(":onwerId", QVariant(ownerId));

    if (!createQuery.exec()) {
        qDebug() << "Ошибка при добавлении кормушки:" << createQuery.lastError().text();
        qDebug() << createQuery.lastQuery();
        return nullptr;
    }

    // Получаем последний вставленный id
    int newId = createQuery.lastInsertId().toInt(); // Преобразуем в int

    // Создаем нового пользователя с полученным id
    Kormushka* newKormushka = new Kormushka(newId, name, type, status); // Предполагается, что конструктор User принимает id
    return newKormushka;
}
Kormushka* KormushkaDB::editKormushka(int& id, QString& name, QString& type, int& status, int& ownerId){
    QSqlQuery editQuery;
    editQuery.prepare("UPDATE Kormushkas SET name=:name, type=:type, type=:status WHERE id=:id");
    editQuery.bindValue(":name", QVariant(name));
    editQuery.bindValue(":type", QVariant(type));
    editQuery.bindValue(":status", QVariant(status));
    editQuery.bindValue(":id", QVariant(id)); // I LOVE PENIS !!!!!!

    if(!editQuery.exec()){
        qDebug() << "Саси мне оу ес саси саси саси";
        return nullptr;
    }

    Kormushka* edittedKormushka = new Kormushka(id, name, type, status);
    return edittedKormushka;
}
bool KormushkaDB::deleteKormushka(int& id){
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Kormushkas WHERE id=:id");
    deleteQuery.bindValue(":id", QVariant(id));
    return deleteQuery.exec();
}
Kormushka* KormushkaDB::getKormushka(int& id){
    QSqlQuery getQuery;
    getQuery.prepare("SELECT id, name, type, status FROM Kormushkas WHERE id=:id");
    getQuery.bindValue(":id", QVariant(id));
    if(getQuery.first()){
        int id = getQuery.value(0).toInt();
        QString receivedName     = getQuery.value(1).toString();
        QString receivedType     = getQuery.value(2).toString();
        int receivedStatus   = getQuery.value(3).toInt();
        Kormushka* kormushk = new Kormushka(id, receivedName, receivedType, receivedStatus);
        return kormushk; // 8====D - - -. . -.
    }
    return nullptr;
}
QList<Kormushka>* KormushkaDB::getKormushkas(){
    QSqlQuery query;
    query.exec("select id, name, type, status from kormushkas");
    QList<Kormushka>* kormusheks = new QList<Kormushka>();
    while(query.next()){
        int id           = query.value(0).toInt();
        QString name     = query.value(1).toString();
        QString type     = query.value(2).toString();
        int status       = query.value(4).toInt();
        Kormushka currentKorm(id, name, type, status);
        kormusheks->push_back(currentKorm);
    }
    return kormusheks;
}

QList<Kormushka>* KormushkaDB::getKormushkas(int &userId){
    QSqlQuery query;
    query.prepare("select id, name, type, status from kormushkas where owner_id=:userId");
    query.bindValue(":userId", QVariant(userId));
    QList<Kormushka>* kormusheks = new QList<Kormushka>();
    while(query.next()){
        int id           = query.value(0).toInt();
        QString name     = query.value(1).toString();
        QString type     = query.value(2).toString();
        int status       = query.value(4).toInt();
        Kormushka currentKorm(id, name, type, status);
        kormusheks->push_back(currentKorm);
    }
    return kormusheks;
}
