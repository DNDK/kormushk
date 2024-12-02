#ifndef CREATEUSERFORM_H
#define CREATEUSERFORM_H

#include <QWidget>
#include "admin.h"
#include "adminwindow.h"

namespace Ui {
class CreateUserForm;
}

class CreateUserForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateUserForm(Admin* db, AdminWindow* adm, QWidget *parent = nullptr);
    ~CreateUserForm();

signals:
    void formClosed(); // Сигнал, который будет испускаться при закрытии

private slots:
    void on_pushButton_2_clicked();
    void on_signupButton_clicked();

protected:
    void closeEvent(QCloseEvent* event) override; // Переопределение closeEvent

private:
    Ui::CreateUserForm *ui;
    Admin* db;
};

#endif // CREATEUSERFORM_H
