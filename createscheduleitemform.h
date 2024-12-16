#ifndef CREATESCHEDULEITEMFORM_H
#define CREATESCHEDULEITEMFORM_H

#include <QDialog>
#include "schedulesdb.h"

namespace Ui {
class CreateScheduleItemForm;
}

class CreateScheduleItemForm : public QDialog
{
    Q_OBJECT

public:
    explicit CreateScheduleItemForm(SchedulesDB*, int, QWidget *parent = nullptr);
    ~CreateScheduleItemForm();

signals:
    void sendNudes();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreateScheduleItemForm *ui;
    SchedulesDB* controller;
    int kormId;
};

#endif // CREATESCHEDULEITEMFORM_H
