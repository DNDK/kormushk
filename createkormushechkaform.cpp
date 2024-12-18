#include "createkormushechkaform.h"
#include "ui_createkormushechkaform.h"
#include "kormushkadb.h"
#include <QMap>
#include <iostream>

CreateKormushechkaForm::CreateKormushechkaForm(KormushkaDB* kormController, QList<User>* users, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateKormushechkaForm)
{
    ui->setupUi(this);
    controller = kormController;
    this->users = users;

    initData();

    // Устанавливаем атрибут для автоматического удаления после закрытия
    setAttribute(Qt::WA_DeleteOnClose);
}

CreateKormushechkaForm::~CreateKormushechkaForm()
{
    delete ui;
    // delete controller;
    // delete niggers;
}


// MUST DELETE NIGGERS
void CreateKormushechkaForm::initData(){
    niggers = controller->getKormushkas();
    for(int i = 0; i < users->length(); i++){
        User user = users->at(i);
        ui->comboBox_2->addItem(user.getUsername(), QVariant(user.getId()));
    }
}

void CreateKormushechkaForm::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();

    QString typeRussian = ui->comboBox->currentText();

    QMap<QString, QString> typeTranslations;
    typeTranslations["С дозатором"] = "dispenser";
    typeTranslations["С датчиком"] = "sensor";
    QString type = typeTranslations[typeRussian];

    int status = 0;

    int userBoxIndex = ui->comboBox_2->currentIndex();
    int userId = ui->comboBox_2->itemData(userBoxIndex).toInt();

    Kormushka* createdUser = controller->createKormushka(name, type, status, userId);
    if (createdUser == nullptr) {
        ui->label_2->setText("Произошла ошибка");
        std::cout << "Ошибка создания пользователя";
        return;
    }

    this->close();
}

void CreateKormushechkaForm::closeEvent(QCloseEvent *event){
    emit kormFormClosed();
    QWidget::closeEvent(event);
}
