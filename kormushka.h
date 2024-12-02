#ifndef KORMUSHKA_H
#define KORMUSHKA_H
#include <QString>

class Kormushka
{
public:
    Kormushka(int, QString&, QString&, int);
    int getId();
    QString getName();
    QString getType();
    int getStatus();
private:
    int id;
    QString name;
    QString type;
    int status;
};

#endif // KORMUSHKA_H
