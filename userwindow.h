#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include "kormushkadb.h"
#include "kormushka.h"

namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(KormushkaDB* kormController, int userId, QWidget *parent = nullptr);
    ~UserWindow();

private:
    Ui::UserWindow *ui;
    void initData();
    KormushkaDB* kormController;
    int userId;
};

#endif // USERWINDOW_H
