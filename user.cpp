#include "user.h"

User::User(int &id, QString &username, QString &password, QString& role) {
    this->id = id;
    this->username = username;
    this->password = password;
    this->role = role;
}

int User::getId(){
    return id;
}

QString User::getUsername(){
    return username;
}

QString User::getPassword(){
    return password;
}

QString User::getRole(){
    return role;
}
