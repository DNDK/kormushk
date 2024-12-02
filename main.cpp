#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>

#include "admin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    // db.setDatabaseName("pablo.db");
    // if(!db.open()){
    //     qDebug() << "Я люблю жирные члены йоу";
    // }
    Admin* database = new Admin("pablo.db");
    MainWindow w(database);
    w.show();
    return a.exec();
}