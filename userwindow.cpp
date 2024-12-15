#include "userwindow.h"
#include "ui_userwindow.h"
#include <QProgressBar>

UserWindow::UserWindow(KormushkaDB* kormController, int userId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    this->kormController = kormController;
    this->userId = userId;
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::initData(){
    QList<Kormushka>* chinazes = kormController->getKormushkas(userId);

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(chinazes->length());
    QStringList headersKorm;
    headersKorm << "ID" << "Название" << "Тип" << "Статус";
    ui->tableWidget->setHorizontalHeaderLabels(headersKorm);

    QMap<QString, QString> typeTranslations;
    typeTranslations["dispenser"] = "С дозатором";
    typeTranslations["sensor"]    = "С датчиком";



    for(int i = 0; i < chinazes->length(); i++){
        Kormushka korm = chinazes->at(i);
        QProgressBar statusBar;
        statusBar.setRange(0, 100);
        statusBar.setValue(korm.getStatus());
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number( korm.getId() ) ) );
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(korm.getName() ) );
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(typeTranslations[korm.getType()] ) );
        ui->tableWidget->setCellWidget(i, 3, &statusBar);
        // ui->tableWidget->setItem(i, 3, QTableWidgetItem(QString::number( korm.getName() ) ) );
        // ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number( korm.getName() ) ) );
    }
}
