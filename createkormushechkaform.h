#ifndef CREATEKORMUSHECHKAFORM_H
#define CREATEKORMUSHECHKAFORM_H

#include <QWidget>

namespace Ui {
class CreateKormushechkaForm;
}

class CreateKormushechkaForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateKormushechkaForm(QWidget *parent = nullptr);
    ~CreateKormushechkaForm();

private:
    Ui::CreateKormushechkaForm *ui;
};

#endif // CREATEKORMUSHECHKAFORM_H
