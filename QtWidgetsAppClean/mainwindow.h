#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
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
#include <QScrollArea>
#include <QVBoxLayout>
#include <QFrame>
#include <QTimer>
#include <QMap>
#include <QHBoxLayout>
#include <QList>
#include <QSpacerItem>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void toggle_buttons(int state);
    void toggle_frame();
    void on_radio_changed();
    void change_label_color(int index);
    void change_label_font(int value);
    void start_progress_fill();
    void update_progress();
    void set_progress_manual();
    void add_dynamic_button();
    void remove_dynamic_button(); // Слот для удаления динамических кнопок

private:
    // === Основные виджеты ===
    QLabel* label;
    QLineEdit* text_input;
    QCheckBox* checkbox;
    QRadioButton* radiobutton1;
    QRadioButton* radiobutton2;
    QRadioButton* radiobutton3;
    QComboBox* combobox;
    QSpinBox* spinbox;
    QSlider* slider;
    QTextEdit* text_edit;
    QListWidget* list_widget;
    QProgressBar* progress;
    QFrame* frame;

    // 10 разных (уникальных) кнопок
    QPushButton* button1, * button2, * button3, * button4, * button5,
        * button6, * button7, * button8, * button9, * button10, * button11;

    // === Вкладки ===
    QTabWidget* tabs;
    QPushButton* tab1_button1;
    QPushButton* tab1_button2;
    QLineEdit* tab1_text;
    QListWidget* tab2_list;
    QCheckBox* tab2_checkbox;
    QPushButton* tab2_button1;
    QPushButton* tab2_button2;

    // === Динамическая зона ===
    QWidget* dynamicArea;
    QVBoxLayout* dynamicLayout;
    QPushButton* addDynBtn;
    QPushButton* deleteDynBtn;
    QList<QPushButton*> dynamicButtons;

    // === Layout главного виджета ===
    QVBoxLayout* mainLayout;

    // === Таймер и связанные поля ===
    QTimer* timer;
    int progress_value;
    bool filling;

    // === Словарь цветов для ComboBox ===
    QMap<QString, QString> color_map;
};
