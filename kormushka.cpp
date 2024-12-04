#include "kormushka.h"

Kormushka::Kormushka(int& id, QString& name, QString& type, int& status) {
    this->id = id;
    this->name = name;
    this->type=type;
    this->status=status;
}

int Kormushka::getId(){
    return id;
}

QString Kormushka::getName(){
    return name;
}
QString Kormushka::getType(){
    return type;
}
int Kormushka::getStatus(){
    return status;
}
