#include "createkormushechkaform.h"
#include "ui_createkormushechkaform.h"

CreateKormushechkaForm::CreateKormushechkaForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateKormushechkaForm)
{
    ui->setupUi(this);
}

CreateKormushechkaForm::~CreateKormushechkaForm()
{
    delete ui;
}
