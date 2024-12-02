#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "admin.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(Admin* db, QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_pushButton_2_clicked();

public slots:
    void on_form_submitted();

private:
    Ui::AdminWindow *ui;
    Admin* db;
    void initInfo();
};

#endif // ADMINWINDOW_H
