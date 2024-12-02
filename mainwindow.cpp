#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"

MainWindow::MainWindow(Admin* db,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->db = db;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    User* user = db->getUser(username, password);
    if(user == nullptr){
        ui->message_label->setText("Тут ты пососал браточек");
    }else{
        ui->message_label->setText("Красавчик, " + user->getUsername());
        AdminWindow *adminWindow = new AdminWindow(db);
        adminWindow->show();
        this->close();
    }
}

