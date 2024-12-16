#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QTime>

class Schedule
{
public:
    Schedule();
    int getId();
    int getKormushkaId();
    QTime getFeedTime();

    void setKormushkaId(int& id);
    void setFeedTime(QTime& time);

private:
    int id;
    int kormushkaId;
    QTime feedTime;

};

#endif // SCHEDULE_H
