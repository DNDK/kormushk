#include "createkormushechkaform.h"
#include "ui_createkormushechkaform.h"
#include "kormushkadb.h"

CreateKormushechkaForm::CreateKormushechkaForm(KormushkaDB* kormController, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateKormushechkaForm)
{
    ui->setupUi(this);
}

CreateKormushechkaForm::~CreateKormushechkaForm()
{
    delete ui;
    delete controller;
    delete niggers;
}

void CreateKormushechkaForm::initData(){
    niggers = controller->getKormushkas();

}

void CreateKormushechkaForm::on_pushButton_clicked()
{

}

