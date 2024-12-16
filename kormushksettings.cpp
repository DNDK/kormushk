#include "kormushksettings.h"
#include "ui_kormushksettings.h"

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
