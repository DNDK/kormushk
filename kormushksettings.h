#ifndef KORMUSHKSETTINGS_H
#define KORMUSHKSETTINGS_H

#include <QWidget>

namespace Ui {
class KormushkSettings;
}

class KormushkSettings : public QWidget
{
    Q_OBJECT

public:
    explicit KormushkSettings(int& id, QWidget *parent = nullptr);
    ~KormushkSettings();

private:
    Ui::KormushkSettings *ui;
};

#endif // KORMUSHKSETTINGS_H
