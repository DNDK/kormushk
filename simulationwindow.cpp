#include "simulationwindow.h"
#include "ui_simulationwindow.h"

SimulationWindow::SimulationWindow(KormushkaDB* kormController, QWidget* parent)
    : QDialog(parent)
    , m_kormController(kormController)
{
    m_groupBoxData = {1, 2, 3, 4, 5, 6, 7, 8};
    m_chinazes = kormController->getKormushkas(); // Сохраняем указатель на QList<Kormushka>

    m_scrollArea = new QScrollArea(this);
    m_contentWidget = new QWidget();
    m_layout = new QGridLayout(m_contentWidget);

    m_scrollArea->setWidget(m_contentWidget);
    m_scrollArea->setWidgetResizable(true);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_scrollArea);

    updateGroupBoxes();
}

void SimulationWindow::resizeEvent(QResizeEvent* event) {
    QDialog::resizeEvent(event); // Вызов базового метода
    updateGroupBoxes();
}

void SimulationWindow::updateGroupBoxes() {
    // Удаляем старые QGroupBox из макета
    QLayoutItem* item;
    while ((item = m_layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    int columns = width() / 200; // Ширина одной groupBox (например, 200)
    int row = 0, column = 0;

    // Используем m_chinazes для создания QGroupBox
    for (int i = 0; i < m_groupBoxData.size(); ++i) {
        QGroupBox* groupBox = new QGroupBox(QString("Group %1").arg((m_groupBoxData)[i])); // Предположим, Kormushka имеет перегруженный оператор <<
        groupBox->setFixedSize(200, 100); // Фиксированный размер
        m_layout->addWidget(groupBox, row, column);

        column++;
        if (column >= columns) {
            column = 0;
            row++;
        }
    }
}
