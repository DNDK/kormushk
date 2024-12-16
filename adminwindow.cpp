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
    // create tables
    // init USERS table
    QList<User>* users = usersController->getUsers();
    this->users = users;
    QStringList headers;
    ui->tableWidget_2->setRowCount(users->length());
    ui->tableWidget_2->setColumnCount(4);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setVisible(false);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableWidget_2->setColumnWidth(0, 20);
    headers << "ID" << "Имя" << "Пароль" << "Роль";
    ui->tableWidget_2->setHorizontalHeaderLabels(headers);
    // ui->tableWidget_2->setHorizontalHeaderLabels(headers);
    for(int i = 0; i < users->length(); i++){
        User user = users->at(i);
        //ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::number(user.getId())));
        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(user.getId()));
        idItem->setTextAlignment(Qt::AlignCenter); // Выравнивание по центру
        ui->tableWidget_2->setItem(i, 0, idItem);
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(user.getUsername()));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(user.getPassword()));
        ui->tableWidget_2->setItem(i, 3, new QTableWidgetItem(user.getRole()));
    }

    // init Kormushkas table
    QList<Kormushka>* korms = kormController->getKormushkas();
    this->kormushks = korms;
    QStringList headersKorm;
    ui->tableWidget->setRowCount(users->length());
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setColumnWidth(0, 20);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    headersKorm << "ID" << "Название" << "Тип" << "Остаток корма";
    ui->tableWidget->setHorizontalHeaderLabels(headersKorm);
    // ui->tableWidget->setHorizontalHeaderLabels(headersKorm);
    for(int i = 0; i < korms->length(); i++){
        Kormushka korm = korms->at(i);
        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(korm.getId()));
        idItem->setTextAlignment(Qt::AlignCenter); // Выравнивание по центру
        ui->tableWidget->setItem(i, 0, idItem);
       // ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(korm.getId())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(korm.getName()));
        // ui->tableWidget->setCellWidget(i, 2, new QTableWidgetItem(korm.getType()));
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
    qDebug() << (users == nullptr);
    CreateKormushechkaForm* form = new CreateKormushechkaForm(kormController, usersController->getUsers(), this);
    connect(form, &CreateKormushechkaForm::kormFormClosed, this, [this](){
        qDebug() << "Паша трицепс";
        initInfo();
    });

    form->show();
}


void AdminWindow::on_LogoutButton_clicked()
{
    QString program = QApplication::applicationFilePath();

    // Запускаем новый экземпляр приложения
    QProcess::startDetached(program);

    // Закрываем текущее приложение
    QApplication::quit();
}

