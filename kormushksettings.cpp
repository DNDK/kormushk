#include "kormushksettings.h"
#include "ui_kormushksettings.h"
#include "createscheduleitemform.h"
#include <QDebug>
#include <QDialog>

KormushkSettings::KormushkSettings(Kormushka kormushk, KormushkaDB* kormController, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::KormushkSettings)
    , kormushk(kormushk) // Инициализация объекта Kormushka
    , kormController(kormController) // Инициализация указателя на KormushkaDB
    , schedController(new SchedulesDB()) // Инициализация указателя на SchedulesDB
{
    ui->setupUi(this);
}

KormushkSettings::~KormushkSettings()
{
    delete ui;
    delete schedController; // Удаление выделенной памяти
}

void KormushkSettings::on_pushButton_2_clicked()
{
    qDebug() << "chleny";
    // Создайте и покажите форму, если нужно
    CreateScheduleItemForm* form = new CreateScheduleItemForm(schedController, kormushk.getId(), this);
    form->show();
}
