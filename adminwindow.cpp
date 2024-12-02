#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "createuserform.h"

AdminWindow::AdminWindow(Admin* db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    this->db = db;
    this->initInfo();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::initInfo(){
    QList<User>* users = db->getUsers();
    QStringList headers;
    ui->tableWidget_2->setRowCount(users->length());
    ui->tableWidget_2->setColumnCount(4);
    headers << "ID" << "Имя" << "Пароль" << "Роль";
    ui->tableWidget_2->setHorizontalHeaderLabels(headers);
    ui->tableWidget_2->setHorizontalHeaderLabels(headers);
    for(int i = 0; i < users->length(); i++){
        User user = users->at(i);
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::number(user.getId())));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(user.getUsername()));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(user.getPassword()));
        ui->tableWidget_2->setItem(i, 3, new QTableWidgetItem(user.getRole()));
    }
}

void AdminWindow::on_form_submitted(){
    initInfo();
}

void AdminWindow::on_pushButton_2_clicked()
{
    CreateUserForm* form = new CreateUserForm(db);

    form->show();
}

