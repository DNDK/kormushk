#include "schedulesdb.h"
#include <QSqlQuery>

SchedulesDB::SchedulesDB() {
    createTable();
}

void SchedulesDB::createTable(){
    QSqlQuery query;
    query.exec("create table if not exists Schedules("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "kormushka_id INTEGER, "
               "feed_time TEXT,"
               "FOREIGN KEY (kormushka_id) REFERENCES Kormushkas(id)"
               ");");
}

void SchedulesDB::createSchedule(int& kormushkaId, QTime feedTime){
    QSqlQuery query;
    query.prepare("insert into Schedules(kormushkaId, feedTime) value(:kormushkaId, :feedTime);");
    query.bindValue(":kormushkaId", QVariant(kormushkaId));

    QString timeFormatted = feedTime.toString("hh:mm");
    query.bindValue(":feedTime", QVariant(timeFormatted));
}

QList<Shedule>* SchedulesDB::getSchedule(int & kormushkaId){
    QSqlQuery query;
    query.prepare("select id, kormushka_id, feed_time from Schedules where kormushka_id=:kormushkaId;");
    query.bindValue(":kormushkaId", QVariant(kormushkaId));
    query.exec();

    QList<Schedule>* scheds = new QList();

    while(query.next()){
        int id = query.value(0).toInt();
        int kormushkaId = query.value(1).toInt();

        QString unFormattedTime = query.value(2).toString();
        QTime feedTime = QTime::fromString(unFormattedTime);

        Schedule sched(id, kormushkaId, feedTime);
        scheds->push_back(sched);
    }
    return scheds;
}

void SchedulesDB::deleteSchedule(int& schedId){
    QSqlQuery query;
    query.prepare("delete from Schedules where id=:schedId");
    query.bindValue(":schedId", schedId);

    query.exec();
}

Schedule* SchedulesDB::editSchedule(int& id, int& kormushkaId, QTime& feedTime){
    QSqlQuery query;
    query.prepare("update Schedules set kormushka_id=:kormId feedTime=:feedTimeStr where id=:id");
    query.bindValue(":id", QVariant(id));
    query.bindValue(":kormId", kormushkaId);
    query.bindValue(":feedTimeStr", QVariant( feedTime.toString("hh:mm") ));

    if(query.exec()){
        return new Schedule(id, kormushkaId, feedTime);
    }
    return nullptr;
}