#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "createuserform.h"
#include "createkormushechkaform.h"
#include "kormushka.h"
#include <QMessageBox>
#include <QDebug>

AdminWindow::AdminWindow(Admin* usersController, KormushkaDB* kormController, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    this->usersController = usersController;
    this->kormController = kormController;

    this->initInfo();
}

AdminWindow::~AdminWindow()
{
    delete ui;
    delete usersController;
    delete kormController;
}

void AdminWindow::initInfo(){
    // init USERS table
    QList<User>* users = usersController->getUsers();
    QStringList headers;
    ui->tableWidget_2->setRowCount(users->length());
    ui->tableWidget_2->setColumnCount(4);
    headers << "ID" << "Имя" << "Пароль" << "Роль";
    ui->tableWidget_2->setHorizontalHeaderLabels(headers);
    // ui->tableWidget_2->setHorizontalHeaderLabels(headers);
    for(int i = 0; i < users->length(); i++){
        User user = users->at(i);
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::number(user.getId())));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(user.getUsername()));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(user.getPassword()));
        ui->tableWidget_2->setItem(i, 3, new QTableWidgetItem(user.getRole()));
    }

    // init Kormushkas table
    QList<Kormushka>* korms = kormController->getKormushkas();
    QStringList headersKorm;
    ui->tableWidget->setRowCount(users->length());
    ui->tableWidget->setColumnCount(4);
    headersKorm << "ID" << "Название" << "Тип" << "Статус";
    ui->tableWidget->setHorizontalHeaderLabels(headersKorm);
    // ui->tableWidget->setHorizontalHeaderLabels(headersKorm);
    for(int i = 0; i < korms->length(); i++){
        Kormushka korm = korms->at(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(korm.getId())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(korm.getName()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(korm.getType()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(korm.getStatus())));
    }

    delete users;
    delete korms;
}

// void AdminWindow::on_form_closed(){
//     QMessageBox::information(this, "ЫЫЫЫЫ", "ЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫ");
//     initInfo();
// }

// void AdminWindow::on_pushButton_2_clicked()
// {
//     CreateUserForm* form = new CreateUserForm(usersController, this);
//     form->show();
// }

void AdminWindow::on_pushButton_2_clicked()
{
    // Создаем форму создания пользователя
    CreateUserForm* form = new CreateUserForm(usersController, this);

    // Подключаем сигнал formClosed к вашему коду
    connect(form, &CreateUserForm::formClosed, this, [this]() {
        qDebug() << "Форма CreateUserForm закрыта.";
        initInfo();
        // Здесь можно обновить интерфейс или выполнить другие действия
    });

    // Показываем форму
    form->show();
}

void AdminWindow::on_pushButton_clicked()
{
    CreateKormushechkaForm* form = new CreateKormushechkaForm(kormController, this);
    connect(form, &CreateKormushechkaForm::kormFormClosed, this, [this](){
        qDebug() << "Паша трицепс";
        initInfo();
    });

    form->show();
}

