#ifndef SCHEDULESDB_H
#define SCHEDULESDB_H

#include "schedule.h"
#include <QList>

class SchedulesDB
{
public:
    SchedulesDB();
    void createSchedule(int&, QTime&);
    QList<Schedule>* getSchedule(int&);
    void deleteSchedule(int&);
    Schedule* editSchedule(int&, QTime&);


private:
    void createTable();
};

#endif // SCHEDULESDB_H


// я отсосал тысячу членов и отсосу столько же
