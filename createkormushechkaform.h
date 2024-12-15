#ifndef CREATEKORMUSHECHKAFORM_H
#define CREATEKORMUSHECHKAFORM_H

#include <QWidget>
#include "kormushka.h"
#include "user.h"
#include "kormushkadb.h"
#include <QList>
#include <QDialog>

namespace Ui {
class CreateKormushechkaForm;
}

class CreateKormushechkaForm : public QDialog
{
    Q_OBJECT

public:
    explicit CreateKormushechkaForm(KormushkaDB* controller, QList<User>* users, QWidget *parent = nullptr);
    ~CreateKormushechkaForm();

signals:
    void kormFormClosed();

private slots:
    void on_pushButton_clicked();

protected:
    void closeEvent(QCloseEvent* event) override; // Переопределение closeEvent

private:
    Ui::CreateKormushechkaForm *ui;
    KormushkaDB* controller;
    void initData();
    QList<Kormushka>* niggers;
    QList<User>* users;
};

#endif // CREATEKORMUSHECHKAFORM_H
