#include "kormushksettings.h"
#include "ui_kormushksettings.h"
#include "createscheduleitemform.h"
#include <QDebug>

KormushkSettings::KormushkSettings(Kormushka kormushk, KormushkaDB* kormController, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::KormushkSettings)
{
    ui->setupUi(this);
    this->kormushk = kormushk;
    this->kormController = kormController;
    this->schedController = new SchedulesDB();
}

KormushkSettings::~KormushkSettings()
{
    delete ui;
    delete schedController;
}

void KormushkSettings::on_pushButton_2_clicked()
{
    qDebug() << "chleny";
    // тут мы сосём пиписич
    // CreateScheduleItemForm* form = new CreateScheduleItemForm(this);
    // connect(form, &CreateScheduleItemForm::shit, this, [this](){
    //     qDebug() << "Я крокодил, крокожу и буду крокодить";
    // });
    // form->show();
}

