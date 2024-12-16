#ifndef KORMUSHKA_H
#define KORMUSHKA_H
#include <QString>

class Kormushka
{
public:
    Kormushka(int&, QString&, QString&, int&, int&);
    int getId() const;
    QString getName() const;
    QString getType() const;
    int getStatus() const;
    int getOwnerId() const;
private:
    int id;
    QString name;
    QString type;
    int status;
    int owner_id;
};

#endif // KORMUSHKA_H
