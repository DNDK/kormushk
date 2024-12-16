#include "kormushksettings.h"
#include "ui_kormushksettings.h"
#include "createscheduleitemform.h"
#include <QDebug>
#include <QDialog>
#include <QList>

KormushkSettings::KormushkSettings(Kormushka kormushk, KormushkaDB* kormController, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::KormushkSettings)
    , kormushk(kormushk) // Инициализация объекта Kormushka
    , kormController(kormController) // Инициализация указателя на KormushkaDB
    , schedController(new SchedulesDB()) // Инициализация указателя на SchedulesDB
{
    ui->setupUi(this);
    initData();
}

KormushkSettings::~KormushkSettings()
{
    delete ui;
    delete schedController; // Удаление выделенной памяти
}

void KormushkSettings::initData(){
    ui->listWidget->clear();
    int id = kormushk.getId();
    QList<Schedule>* kaka = schedController->getSchedule(id);
    qDebug() << kaka->length();
    for(int i = 0; i < kaka->length(); i++){
        Schedule piska = kaka->at(i);
        QTime time = piska.getFeedTime();
        QString sussy = time.toString("HH:mm");
        ui->listWidget->addItem(sussy);
    }
}

void KormushkSettings::on_pushButton_2_clicked()
{
    qDebug() << "chleny";
    // Создайте и покажите форму, если нужно
    CreateScheduleItemForm* form = new CreateScheduleItemForm(schedController, kormushk.getId(), this);
    connect(form, &CreateScheduleItemForm::sendNudes, this, [this](){
        qDebug() << "Паша трицепс";
        initData();
    });
    form->show();
}
