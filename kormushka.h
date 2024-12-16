#ifndef KORMUSHKA_H
#define KORMUSHKA_H
#include <QString>

class Kormushka
{
public:
    Kormushka(int&, QString&, QString&, int&);
    int getId() const;
    QString getName() const;
    QString getType() const;
    int getStatus() const;
private:
    int id;
    QString name;
    QString type;
    int status;
};

#endif // KORMUSHKA_H
