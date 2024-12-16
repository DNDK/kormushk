#ifndef KORMUSHKSETTINGS_H
#define KORMUSHKSETTINGS_H

#include <QWidget>
#include "kormushka.h"
#include "schedulesdb.h"
#include "kormushkadb.h"

namespace Ui {
class KormushkSettings;
}

class KormushkSettings : public QWidget
{
    Q_OBJECT

public:
    explicit KormushkSettings(Kormushka, KormushkaDB* kormController, QWidget *parent = nullptr);
    ~KormushkSettings();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::KormushkSettings *ui;
    Kormushka kormushk;
    SchedulesDB* schedController;
    KormushkaDB* kormController;
};

#endif // KORMUSHKSETTINGS_H
