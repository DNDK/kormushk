#include "createscheduleitemform.h"
#include "ui_createscheduleitemform.h"

CreateScheduleItemForm::CreateScheduleItemForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateScheduleItemForm)
{
    ui->setupUi(this);
}

CreateScheduleItemForm::~CreateScheduleItemForm()
{
    delete ui;
}

void CreateScheduleItemForm::on_pushButton_clicked()
{

}

