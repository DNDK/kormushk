#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "admin.h"
#include "kormushkadb.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(Admin* usersController, KormushkaDB* kormController, QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_pushButton_2_clicked();
    // void on_form_closed();

    void on_pushButton_clicked();

private:
    Ui::AdminWindow *ui;
    Admin* usersController;
    KormushkaDB* kormController;
    void initInfo();
};

#endif // ADMINWINDOW_H
