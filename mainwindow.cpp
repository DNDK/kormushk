#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"

MainWindow::MainWindow(Admin* usersController, KormushkaDB* kormController, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->usersController = usersController;
    this->kormController = kormController;
}

MainWindow::~MainWindow()
{
    delete ui;
    // delete usersController;
    // delete kormController;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    User* user = usersController->getUser(username, password);
    if(user == nullptr){
        ui->message_label->setText("Тут ты пососал браточек");
    }else{
        ui->message_label->setText("Красавчик, " + user->getUsername());
        AdminWindow *adminWindow = new AdminWindow(usersController, kormController);
        adminWindow->show();
        this->close();
    }
}

