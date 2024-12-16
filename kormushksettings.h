#ifndef KORMUSHKSETTINGS_H
#define KORMUSHKSETTINGS_H

#include <QWidget>
#include <QDialog>
#include "kormushka.h" // Добавьте заголовок Kormushka
#include "kormushkadb.h" // Заголовок для KormushkaDB
#include "schedulesdb.h" // Заголовок для SchedulesDB

namespace Ui {
class KormushkSettings;
}

class KormushkSettings : public QDialog
{
    Q_OBJECT

public:
    explicit KormushkSettings(Kormushka kormushk, KormushkaDB* kormController, QWidget *parent = nullptr);
    ~KormushkSettings();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::KormushkSettings *ui;
    Kormushka kormushk; // Объект Kormushka
    KormushkaDB* kormController; // Указатель на KormushkaDB
    SchedulesDB* schedController; // Указатель на SchedulesDB
    void initData();
};

#endif // KORMUSHKSETTINGS_H
