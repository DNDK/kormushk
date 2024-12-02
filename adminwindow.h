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

private:
    Ui::AdminWindow *ui;
    Admin* db;
    void initInfo();
};

#endif // ADMINWINDOW_H
