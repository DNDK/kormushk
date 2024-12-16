#include "kormushksettings.h"
#include "ui_kormushksettings.h"
#include "createscheduleitemform.h"

KormushkSettings::KormushkSettings(int& id, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::KormushkSettings)
{
    ui->setupUi(this);
    this->id = id;
}

KormushkSettings::~KormushkSettings()
{
    delete ui;
}

void KormushkSettings::on_pushButton_2_clicked()
{
    // тут мы сосём пиписич
    CreateScheduleItemForm* form = new CreateScheduleItemForm(this);
    form->show();

}

