#include "createuserform.h"
#include "ui_createuserform.h"
#include "adminwindow.h"
#include <iostream>
#include <QMap>

// Определяем сигнал в заголовочном файле
CreateUserForm::CreateUserForm(Admin* db, AdminWindow* adm, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateUserForm)
{
    ui->setupUi(this);
    this->db = db;

    // Устанавливаем атрибут для автоматического удаления после закрытия
    setAttribute(Qt::WA_DeleteOnClose);
}

CreateUserForm::~CreateUserForm()
{
    delete ui;
}

void CreateUserForm::on_pushButton_2_clicked()
{
    QString username = ui->usernameLine->text();
    QString password = ui->passwordLine->text();
    QString roleRussian = ui->roleCombo->currentText();

    QMap<QString, QString> roleNames;
    roleNames["Администратор"] = "admin";
    roleNames["Пользователь"] = "user";

    QString role = roleNames[roleRussian];

    User* createdUser = db->addUser(username, password, role);
    if (createdUser == nullptr) {
        ui->label_4->setText("Произошла ошибка");
        std::cout << "Ошибка создания пользователя";
        return;
    }

    // Закрываем форму
    this->close();
}

void CreateUserForm::on_signupButton_clicked()
{
    QString username = ui->usernameLine->text();
    QString password = ui->passwordLine->text();
    QString roleRussian = ui->roleCombo->currentText();

    QMap<QString, QString> roleNames;
    roleNames["Администратор"] = "admin";
    roleNames["Пользователь"] = "user";

    QString role = roleNames[roleRussian];

    User* createdUser = db->addUser(username, password, role);
    if (createdUser == nullptr) {
        ui->label_4->setText("Произошла ошибка");
        std::cout << "Ошибка создания пользователя";
        return;
    }

    // Закрываем форму
    this->close();
}

// Переопределяем closeEvent и испускаем пользовательский сигнал
void CreateUserForm::closeEvent(QCloseEvent* event)
{
    emit formClosed(); // Испускаем сигнал при закрытии
    QWidget::closeEvent(event); // Вызываем базовую реализацию
}
