#include "createscheduleitemform.h"
#include "ui_createscheduleitemform.h"
#include <QDebug>

CreateScheduleItemForm::CreateScheduleItemForm(SchedulesDB* controller, int kormId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateScheduleItemForm)
    , controller(controller)
    , kormId(kormId)
{
    ui->setupUi(this);
}

CreateScheduleItemForm::~CreateScheduleItemForm()
{
    delete ui;
}

void CreateScheduleItemForm::on_pushButton_clicked()
{
    QString selTime = ui->timeEdit->text();
    qDebug() << selTime;
    QTime time = QTime::fromString(selTime, "hh:mm");
    controller->createSchedule(kormId, time);
    emit sendNudes();
    this->close();
}

