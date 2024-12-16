#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QDialog>
#include <QVector>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QResizeEvent>
#include <QScrollArea>
#include "kormushka.h"
#include "kormushkadb.h"

class KormushkaDB; // Предварительное объявление класса

class SimulationWindow : public QDialog {
    Q_OBJECT

public:
    SimulationWindow(KormushkaDB* kormController, QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void updateGroupBoxes();

    QVector<int> m_groupBoxData;
    QGridLayout* m_layout;
    QScrollArea* m_scrollArea;
    QWidget* m_contentWidget;
    KormushkaDB* m_kormController; // Хранение указателя на KormushkaDB
    QList<Kormushka>* m_chinazes;
};

#endif // SIMULATIONWINDOW_H
