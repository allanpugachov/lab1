
#include "mainwindow.h"
#include <QScrollArea>
#include <QFont>
#include <QHBoxLayout>
#include <QPushButton>
#include <QList>
#include <QSpacerItem>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QComboBox>
#include <QSpinBox>
#include <QSlider>
#include <QTabWidget>
#include <QTextEdit>
#include <QListWidget>
#include <QProgressBar>
#include <QFrame>
#include <QTimer>
#include <QVBoxLayout>
#include <QGridLayout> // Добавляем QGridLayout

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , progress_value(0)
    , filling(false)
{
    this->resize(1000, 800);
    this->setMinimumSize(800, 600);

    QWidget* centralWidget = new QWidget(this);
    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(centralWidget);
    setCentralWidget(scrollArea);

    mainLayout = new QVBoxLayout(centralWidget);

    color_map["Белый"] = "white";
    color_map["Желтый"] = "yellow";
    color_map["Циан"] = "cyan";
    color_map["Магента"] = "magenta";

    // --- Инициализация всех виджетов ---
    label = new QLabel("Привет! Это QLabel", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("background-color: white;");
    label->setFixedHeight(50);

    text_input = new QLineEdit("Текстовый ввод", this);
    checkbox = new QCheckBox("Кнопки включены", this);
    checkbox->setChecked(true);

    radiobutton1 = new QRadioButton("Вариант 1", this);
    radiobutton2 = new QRadioButton("Вариант 2", this);
    radiobutton3 = new QRadioButton("Вариант 3", this);

    combobox = new QComboBox(this);
    combobox->addItem("Белый");
    combobox->addItem("Желтый");
    combobox->addItem("Циан");
    combobox->addItem("Магента");

    spinbox = new QSpinBox(this);
    spinbox->setRange(0, 100);
    spinbox->setValue(50);

    slider = new QSlider(Qt::Horizontal, this);
    slider->setRange(10, 30);
    slider->setValue(label->font().pointSize());

    text_edit = new QTextEdit(this);
    text_edit->setPlainText("Это многострочное текстовое поле. Вы можете ввести здесь любой текст.");

    list_widget = new QListWidget(this);
    list_widget->addItem("Общий элемент списка 1");
    list_widget->addItem("Общий элемент списка 2");

    progress = new QProgressBar(this);
    progress->setRange(0, 100);
    progress->setValue(progress_value);

    frame = new QFrame(this);
    frame->setFrameStyle(QFrame::Box | QFrame::Plain);
    frame->setLineWidth(2);
    frame->setVisible(false);
    QVBoxLayout* frameLayout = new QVBoxLayout(frame);
    QLabel* frameLabel = new QLabel("Это содержимое внутри QFrame", frame);
    frameLayout->addWidget(frameLabel);
    QPushButton* frameButton = new QPushButton("Кнопка внутри QFrame", frame);
    frameLayout->addWidget(frameButton);


    // --- Кнопки с обновленными описаниями ---
    button1 = new QPushButton("Установить текст 'Нажата кнопка 1'", this);
    button2 = new QPushButton("Сделать метку ЖЕЛТОЙ", this);
    button3 = new QPushButton("Сделать метку ЦИАН", this);
    button4 = new QPushButton("Запустить заполнение прогресс-бара", this);
    button5 = new QPushButton("Очистить редактор текста", this);
    button6 = new QPushButton("Добавить текст в редактор", this);
    button7 = new QPushButton("Показать/скрыть рамку", this);
    button8 = new QPushButton("Установить шрифт метки 20pt", this);
    button9 = new QPushButton("Прогресс-бар 50%", this);
    button10 = new QPushButton("Поменять цвет этой кнопки", this);

    button1->setObjectName("button1");
    button2->setObjectName("button2");
    button3->setObjectName("button3");

    button1->setCheckable(true);
    button2->setCheckable(true);
    button3->setCheckable(true);

    // QTabWidget и его содержимое
    tabs = new QTabWidget(this);
    QWidget* tab1 = new QWidget();
    QWidget* tab2 = new QWidget();
    tabs->addTab(tab1, "Вкладка 1");
    tabs->addTab(tab2, "Вкладка 2");

    QVBoxLayout* tab1Layout = new QVBoxLayout(tab1);
    tab1_button1 = new QPushButton("Показать 'Кнопка1 нажата' на метке", tab1);
    tab1_button2 = new QPushButton("Добавить элемент в общий список", tab1);
    tab1_text = new QLineEdit(tab1);
    tab1_text->setPlaceholderText("Текст на вкладке 1...");
    tab1Layout->addWidget(tab1_button1);
    tab1Layout->addWidget(tab1_button2);
    tab1Layout->addWidget(tab1_text);
    tab1Layout->addStretch();

    QVBoxLayout* tab2Layout = new QVBoxLayout(tab2);
    tab2_list = new QListWidget(tab2);
    tab2_list->addItem("Элемент вкладки 2.1");
    tab2_list->addItem("Элемент вкладки 2.2");
    tab2_checkbox = new QCheckBox("Чекбокс (Tab 2)", tab2);
    tab2_button1 = new QPushButton("Выбрать 1-й элемент списка на вкладке", tab2);
    tab2_button2 = new QPushButton("Отметить чекбокс на вкладке", tab2);
    tab2Layout->addWidget(tab2_list);
    tab2Layout->addWidget(tab2_checkbox);
    tab2Layout->addWidget(tab2_button1);
    tab2Layout->addWidget(tab2_button2);
    tab2Layout->addStretch();


    // --- Динамическая зона ---
    dynamicArea = new QWidget(this);
    dynamicLayout = new QVBoxLayout(dynamicArea);
    dynamicLayout->setAlignment(Qt::AlignTop);

    // Создаем кнопки управления динамическими кнопками
    addDynBtn = new QPushButton("Добавить динамическую кнопку", dynamicArea);
    deleteDynBtn = new QPushButton("Удалить последнюю динамическую кнопку", dynamicArea);

    // Создаем горизонтальный Layout для кнопок управления
    QHBoxLayout* dynamicControlsLayout = new QHBoxLayout();
    dynamicControlsLayout->addWidget(addDynBtn);
    dynamicControlsLayout->addWidget(deleteDynBtn);

    // Добавляем Layout с кнопками управления в dynamicLayout
    dynamicLayout->addLayout(dynamicControlsLayout);

    // Добавляем растягивающийся пробел в dynamicLayout, чтобы динамические кнопки прижимались вверх
    dynamicLayout->addStretch();

    // Подключаем слоты
    connect(addDynBtn, &QPushButton::clicked, this, &MainWindow::add_dynamic_button);
    connect(deleteDynBtn, &QPushButton::clicked, this, &MainWindow::remove_dynamic_button);


    // --- Добавляем все в mainLayout ---
    mainLayout->addWidget(tabs);
    mainLayout->addWidget(label);

    // Используем QGridLayout для 10 кнопок ***
    QGridLayout* buttonsGridLayout = new QGridLayout();
    // Добавляем кнопки в сетку: 2 строки по 5 кнопок
    buttonsGridLayout->addWidget(button1, 0, 0); // строка 0, колонка 0
    buttonsGridLayout->addWidget(button2, 0, 1); // строка 0, колонка 1
    buttonsGridLayout->addWidget(button3, 0, 2); // строка 0, колонка 2
    buttonsGridLayout->addWidget(button4, 0, 3); // строка 0, колонка 3
    buttonsGridLayout->addWidget(button5, 0, 4); // строка 0, колонка 4
    buttonsGridLayout->addWidget(button6, 1, 0); // строка 1, колонка 0
    buttonsGridLayout->addWidget(button7, 1, 1); // строка 1, колонка 1
    buttonsGridLayout->addWidget(button8, 1, 2); // строка 1, колонка 2
    buttonsGridLayout->addWidget(button9, 1, 3); // строка 1, колонка 3
    buttonsGridLayout->addWidget(button10, 1, 4); // строка 1, колонка 4
    mainLayout->addLayout(buttonsGridLayout);
    

    mainLayout->addWidget(new QLabel("Текстовое поле:"));
    mainLayout->addWidget(text_input);
    mainLayout->addWidget(checkbox);

    QHBoxLayout* radioLayout = new QHBoxLayout();
    radioLayout->addWidget(radiobutton1);
    radioLayout->addWidget(radiobutton2);
    radioLayout->addWidget(radiobutton3);
    mainLayout->addLayout(radioLayout);

    mainLayout->addWidget(new QLabel("Выбор цвета QLabel:"));
    mainLayout->addWidget(combobox);
    mainLayout->addWidget(new QLabel("Размер шрифта QLabel:"));
    mainLayout->addWidget(slider);
    mainLayout->addWidget(new QLabel("Редактор текста:"));
    mainLayout->addWidget(text_edit);
    mainLayout->addWidget(new QLabel("Список:"));
    mainLayout->addWidget(list_widget);

    QHBoxLayout* progressLayout = new QHBoxLayout();
    progressLayout->addWidget(new QLabel("Прогресс-бар:"));
    progressLayout->addWidget(progress);
    progressLayout->addWidget(new QLabel("Установить вручную:"));
    progressLayout->addWidget(spinbox);
    mainLayout->addLayout(progressLayout);

    mainLayout->addWidget(frame);
    mainLayout->addWidget(new QLabel("Зона для динамических кнопок:"));
    mainLayout->addWidget(dynamicArea);

    // --- Таймер ---
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::update_progress);

    // --- Сигналы ---
    connect(button1, &QPushButton::clicked, [this] { label->setText("Нажата кнопка 1"); });
    connect(button2, &QPushButton::clicked, [this] { label->setStyleSheet("background-color: yellow;"); });
    connect(button3, &QPushButton::clicked, [this] { label->setStyleSheet("background-color: cyan;"); });
    connect(button4, &QPushButton::clicked, this, &MainWindow::start_progress_fill);
    connect(button5, &QPushButton::clicked, [this] { text_edit->clear(); });
    connect(button6, &QPushButton::clicked, [this] { text_edit->append("Добавлен текст"); });
    connect(button7, &QPushButton::clicked, this, &MainWindow::toggle_frame);
    connect(button8, &QPushButton::clicked, [this] { label->setFont(QFont("Arial", 20)); });
    connect(button9, &QPushButton::clicked, [this] { progress->setValue(50); });
    connect(button10, &QPushButton::clicked, [this] { button10->setStyleSheet("background-color: magenta; color:white;"); });

    connect(tab1_button1, &QPushButton::clicked, [this] { label->setText("Вкладка1 кнопка1 нажата"); });
    connect(tab1_button2, &QPushButton::clicked, [this] { list_widget->addItem("Новый элемент из вкладки1"); });
    connect(tab2_button1, &QPushButton::clicked, [this] { tab2_list->setCurrentRow(0); });
    connect(tab2_button2, &QPushButton::clicked, [this] { tab2_checkbox->setChecked(true); });

    connect(checkbox, &QCheckBox::checkStateChanged, this, &MainWindow::toggle_buttons);

    connect(radiobutton1, &QRadioButton::toggled, this, &MainWindow::on_radio_changed);
    connect(radiobutton2, &QRadioButton::toggled, this, &MainWindow::on_radio_changed);
    connect(radiobutton3, &QRadioButton::toggled, this, &MainWindow::on_radio_changed);
    connect(combobox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::change_label_color);
    connect(slider, &QSlider::valueChanged, this, &MainWindow::change_label_font);
    connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::set_progress_manual);

    mainLayout->addStretch();
}

MainWindow::~MainWindow()
{
    qDeleteAll(dynamicButtons);
    dynamicButtons.clear();
}

// -------------------- Слот: Добавление динамической кнопки --------------------
void MainWindow::add_dynamic_button()
{
    QString buttonText = QString("Динамическая кнопка %1").arg(dynamicButtons.size() + 1);
    QPushButton* newButton = new QPushButton(buttonText);
    newButton->setFixedSize(160, 40);

    // Вставляем новую кнопку ПЕРЕД растягивающимся пробелом.
    // Если dynamicLayout содержит (dynamicControlsLayout, stretch),
    // то stretch находится на dynamicLayout->count() - 1.
    // Вставляем новую кнопку на dynamicLayout->count() - 1 (перед stretch).
    dynamicLayout->insertWidget(dynamicLayout->count() - 1, newButton);

    dynamicButtons.append(newButton);
}

// -------------------- Слот: Удаление динамической кнопки --------------------
void MainWindow::remove_dynamic_button()
{
    if (!dynamicButtons.isEmpty()) {
        QPushButton* lastButton = dynamicButtons.last();
        dynamicLayout->removeWidget(lastButton);
        dynamicButtons.removeLast();
        delete lastButton;
    }
}


// -------------------- Реализация других слотов --------------------

void MainWindow::toggle_buttons(int state)
{
    // Получаем указатели на кнопки по их objectName.
    QPushButton* btn1 = this->findChild<QPushButton*>("button1");
    QPushButton* btn2 = this->findChild<QPushButton*>("button2");
    QPushButton* btn3 = this->findChild<QPushButton*>("button3");

    // Включаем или выключаем кнопки в зависимости от состояния чекбокса.
    if (btn1) btn1->setEnabled(state == Qt::Checked);
    if (btn2) btn2->setEnabled(state == Qt::Checked);
    if (btn3) btn3->setEnabled(state == Qt::Checked);
}

void MainWindow::toggle_frame()
{
    frame->setVisible(!frame->isVisible());
}

void MainWindow::on_radio_changed()
{
    if (radiobutton1->isChecked()) {
        label->setText("Выбрана RadioButton 1");
    }
    else if (radiobutton2->isChecked()) {
        label->setText("Выбрана RadioButton 2");
    }
    else if (radiobutton3->isChecked()) {
        label->setText("Выбрана RadioButton 3");
    }
}

void MainWindow::change_label_color(int index)
{
    QString colorNameKey = combobox->itemText(index);
    if (color_map.contains(colorNameKey)) {
        label->setStyleSheet("background-color: " + color_map[colorNameKey] + ";");
    }
}

void MainWindow::change_label_font(int value)
{
    QFont font = label->font();
    font.setPointSize(value);
    label->setFont(font);
}

void MainWindow::start_progress_fill()
{
    if (!filling) {
        progress_value = 0;
        progress->setValue(progress_value);
        timer->start(100);
        filling = true;
    }
}

void MainWindow::update_progress()
{
    if (progress_value < 100) {
        progress_value++;
        progress->setValue(progress_value);
    }
    else {
        timer->stop();
        filling = false;
    }
}

void MainWindow::set_progress_manual()
{
    progress->setValue(spinbox->value());
    progress_value = spinbox->value();
    if (filling) {
        timer->stop();
        filling = false;
    }
}
