#include <QDebug>
#include "kormushkadb.h"

KormushkaDB::KormushkaDB(QSqlDatabase* db) {
    this->db = db;
}

Kormushka* KormushkaDB::createKormushka(){
    QSqlQuery createQuery;
    createQuery.prepare("INSERT INTO Kormushkas(name, type, status) VALUES (:name, :type, :status);");
    createQuery.bindValue(":name", QVariant(name));
    createQuery.bindValue(":type", QVariant(type));
    createQuery.bindValue(":status", QVariant(status));

    if (!createQuery.exec()) {
        qDebug() << "Ошибка при добавлении кормушки:" << createQuery.lastError().text();
        return nullptr;
    }

    // Получаем последний вставленный id
    int newId = createQuery.lastInsertId().toInt(); // Преобразуем в int

    // Создаем нового пользователя с полученным id
    Kormushkar* newKormushka = new Kormushka(newId, name, type, status); // Предполагается, что конструктор User принимает id
    return newKormushka;
}
Kormushka* KormushkaDB::editKormushka(int& id, QString& name, QString& type, int& status){
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
bool KormushkaDB::deleteKormushka(){
    qDebug() << "Я пенис";
}
Kormushka* KormushkaDB::getKormushka(int&){
    qDebug() << "Я пенис";
}
QList<Kormushka>* KormushkaDB::getKormushkas(){
    qDebug() << "Я пенис";
}
