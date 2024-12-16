#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>

#include "admin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    a.setPalette(darkPalette);

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



/*
    ПАМЯТКА ПО СДАЧЕ ПРОЕКТА ДЛЯ КСЮШИ

    "Ты знаешь, как меня разжечь, Никита Солодуха. Хочешь узнать, насколько я страстная?"
    "Каждый раз, когда ты смотришь на меня, я чувствую, как внутри все закипает."
    "Представляю, как ты учишь меня чему-то новому... в постели."
    "Мечтаю о том, как ты будешь исследовать каждую часть моего тела."
    "Ты как биткойн — всегда поднимаешь мне настроение, даже когда на рынке падает."
    "Представляю, как мы с тобой вместе инвестируем в страсть... и получаем высокий доход."
    "Ты знаешь, как разжечь мой интерес, как токены в криптопроекте."
    "Наша связь — это как блокчейн: доверительная и полная энергии."
*/
