#include "kormushka.h"

Kormushka::Kormushka(int& id, QString& name, QString& type, int& status, int& owner_id) {
    this->id = id;
    this->name = name;
    this->type=type;
    this->status=status;
}

int Kormushka::getId() const{
    return id;
}

QString Kormushka::getName() const{
    return name;
}
QString Kormushka::getType() const{
    return type;
}
int Kormushka::getStatus() const{
    return status;
}
