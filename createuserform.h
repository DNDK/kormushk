#ifndef CREATEUSERFORM_H
#define CREATEUSERFORM_H

#include <QWidget>
#include "admin.h"
#include "adminwindow.h"
#include <functional>

namespace Ui {
class CreateUserForm;
}

class CreateUserForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateUserForm(Admin*, AdminWindow*, QWidget *parent = nullptr);
    ~CreateUserForm();

private slots:
    void on_pushButton_2_clicked();

    void on_signupButton_clicked();

private:
    Ui::CreateUserForm *ui;
    Admin* db;

};


#endif // CREATEUSERFORM_H
