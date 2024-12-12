#ifndef CREATEKORMUSHECHKAFORM_H
#define CREATEKORMUSHECHKAFORM_H

#include <QWidget>
#include "kormushka.h"
#include "kormushkadb.h"
#include <QList>

namespace Ui {
class CreateKormushechkaForm;
}

class CreateKormushechkaForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateKormushechkaForm(KormushkaDB* controller, QWidget *parent = nullptr);
    ~CreateKormushechkaForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreateKormushechkaForm *ui;
    KormushkaDB* controller;
    void initData();
    QList<Kormushka>* niggers;
};

#endif // CREATEKORMUSHECHKAFORM_H
