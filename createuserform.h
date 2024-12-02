#ifndef CREATEUSERFORM_H
#define CREATEUSERFORM_H

#include <QWidget>
#include "admin.h"
#include <functional>

namespace Ui {
class CreateUserForm;
}

class CreateUserForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateUserForm(Admin*, QWidget *parent = nullptr);
    ~CreateUserForm();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::CreateUserForm *ui;
    Admin* db;

signals:
    void button();
};


#endif // CREATEUSERFORM_H
