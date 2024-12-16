#include "simulationwindow.h"
#include "ui_simulationwindow.h"
#include <QProgressBar>
#include <QLabel>
#include <QListWidget>

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

    QList<Kormushka>* kaka = m_kormController->getKormushkas();
    qDebug() << kaka->length();
    for (int i = 0; i < kaka->length(); i++) {
        Kormushka piska = kaka->at(i);

        // Создание QGroupBox
        QGroupBox* groupBox = new QGroupBox(QString("Кормушка %1").arg(piska.getName()));
        groupBox->setFixedSize(200, 150); // Увеличиваем высоту для размещения элементов

        // Создание вертикального макета для groupBox
        QVBoxLayout* groupLayout = new QVBoxLayout(groupBox);

        // Создание ProgressBar
        QProgressBar* progressBar = new QProgressBar();
        progressBar->setRange(0, 100); // Установка диапазона от 0 до 100
        progressBar->setValue(piska.getStatus()); // Пример значения, можно заменить на нужное

        // Создание QLabel
        QLabel* label = new QLabel(QString("Значение: %1").arg(progressBar->value()));

        // Создание QListWidget
        QListWidget* listWidget = new QListWidget();
        listWidget->addItems({"Item 1", "Item 2", "Item 3"}); // Пример элементов

        // Добавление элементов в groupLayout
        groupLayout->addWidget(progressBar);
        groupLayout->addWidget(label);
        groupLayout->addWidget(listWidget);

        // Добавление groupBox в основной макет
        m_layout->addWidget(groupBox, row, column);

        column++;
        if (column >= columns) {
            column = 0;
            row++;
        }
    }
}
