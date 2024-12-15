#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"
#include "userwindow.h"

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


// Padlo pidoras. Padlo ne rabotaet
void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    User* user = usersController->getUser(username, password);
    if(user == nullptr){
        ui->message_label->setText("Тут ты пососал браточек");
    }else{
        ui->message_label->setText("Красавчик, " + user->getUsername());
        if(user->getRole() == "admin"){
            AdminWindow *adminWindow = new AdminWindow(usersController, kormController);
            adminWindow->show();
            this->close();
        }else{
            UserWindow* userWindow = new UserWindow(kormController, user->getId());
            userWindow->show();
            this->close();
        }
    }
}

