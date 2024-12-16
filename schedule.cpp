#include "schedule.h"

Schedule::Schedule(int& id, int& kormushkaId, QTime& feedTime) {
    this->id = id;
    this->kormushkaId = kormushkaId;
    this->feedTime = feedTime;
}

int Schedule::getId(){
    return id;
}

int Schedule::getKormushkaId(){
    return kormushkaId;
}

QTime Schedule::getFeedTime(){
    return feedTime;
}

void Schedule::setKormushkaId(int& id){
    this->id = id;
}

void Schedule::setFeedTime(QTime& feedTime){
    this->feedTime = feedTime;
}
