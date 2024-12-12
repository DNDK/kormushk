#include "createkormushechkaform.h"
#include "ui_createkormushechkaform.h"
#include "kormushkadb.h"

CreateKormushechkaForm::CreateKormushechkaForm(KormushkaDB* kormController, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateKormushechkaForm)
{
    ui->setupUi(this);

    // Устанавливаем атрибут для автоматического удаления после закрытия
    setAttribute(Qt::WA_DeleteOnClose);
}

CreateKormushechkaForm::~CreateKormushechkaForm()
{
    delete ui;
    // delete controller;
    // delete niggers;
}

void CreateKormushechkaForm::initData(){
    niggers = controller->getKormushkas();
}

void CreateKormushechkaForm::on_pushButton_clicked()
{
    this->close();
}

void CreateKormushechkaForm::closeEvent(QCloseEvent *event){
    emit kormFormClosed();
    QWidget::closeEvent(event);
}
