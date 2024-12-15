#include "userwindow.h"
#include "ui_userwindow.h"
#include <QProgressBar>
#include <QPushButton>
#include <QDebug>
#include <QIcon>
#include <iostream>

UserWindow::UserWindow(KormushkaDB* kormController, int userId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    this->kormController = kormController;
    this->userId = userId;
    initData();
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::initData(){
    QList<Kormushka>* chinazes = kormController->getKormushkas(userId);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(chinazes->length());
    QStringList headersKorm;
    headersKorm << QString::number(userId) << "Название" << "Тип" << "Статус";
    ui->tableWidget->setHorizontalHeaderLabels(headersKorm);

    QMap<QString, QString> typeTranslations;
    typeTranslations["dispenser"] = "С дозатором";
    typeTranslations["sensor"]    = "С датчиком";

    qDebug() << chinazes->length();

    for(int i = 0; i < chinazes->length(); i++){
        Kormushka korm = chinazes->at(i);
        qDebug() << korm.getName();
        QProgressBar* statusBar = new QProgressBar();
        statusBar->setRange(0, 100);
        // statusBar->setValue(korm.getStatus());
        statusBar->setValue(20);
        QIcon icon(":/images/cog-heart.png");
        QPushButton* kormButton = new QPushButton();
        // kormButton->setText("Настроить");
        kormButton->setIcon(icon);
        connect(kormButton, &QPushButton::clicked, this, [this](){
            qDebug() << this->userId;
        });

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number( korm.getId() ) ) );
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(korm.getName() ) );
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(typeTranslations[korm.getType()] ) );
        ui->tableWidget->setCellWidget(i, 3, statusBar);
        ui->tableWidget->setCellWidget(i, 4, kormButton);
        // ui->tableWidget->setItem(i, 3, QTableWidgetItem(QString::number( korm.getName() ) ) );
        // ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number( korm.getName() ) ) );
    }
}
