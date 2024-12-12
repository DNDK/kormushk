#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>

#include "admin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("pablo.db");
    if(!db.open()){
        qDebug() << "Я люблю жирные члены йоу";
        return -1;
    }
    Admin* usersController = new Admin(&db);
    KormushkaDB* kormsController = new KormushkaDB(&db);
    MainWindow w(usersController, kormsController);
    w.show();
    return a.exec();
}
