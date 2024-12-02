#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(int&, QString&, QString&, QString&);
    int getId();
    QString getUsername();
    QString getPassword();
    QString getRole();
private:
    int id;
    QString username;
    QString password;
    QString role;
};

#endif // USER_H
