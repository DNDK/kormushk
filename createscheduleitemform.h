#ifndef CREATESCHEDULEITEMFORM_H
#define CREATESCHEDULEITEMFORM_H

#include <QDialog>

namespace Ui {
class CreateScheduleItemForm;
}

class CreateScheduleItemForm : public QDialog
{
    Q_OBJECT

public:
    explicit CreateScheduleItemForm(QWidget *parent = nullptr);
    ~CreateScheduleItemForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreateScheduleItemForm *ui;
};

#endif // CREATESCHEDULEITEMFORM_H
