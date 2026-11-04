/********************************************************************************
** Form generated from reading UI file 'QtWidgetsAppClean.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPCLEAN_H
#define UI_QTWIDGETSAPPCLEAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsAppCleanClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsAppCleanClass)
    {
        if (QtWidgetsAppCleanClass->objectName().isEmpty())
            QtWidgetsAppCleanClass->setObjectName("QtWidgetsAppCleanClass");
        QtWidgetsAppCleanClass->resize(600, 400);
        menuBar = new QMenuBar(QtWidgetsAppCleanClass);
        menuBar->setObjectName("menuBar");
        QtWidgetsAppCleanClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsAppCleanClass);
        mainToolBar->setObjectName("mainToolBar");
        QtWidgetsAppCleanClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtWidgetsAppCleanClass);
        centralWidget->setObjectName("centralWidget");
        QtWidgetsAppCleanClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtWidgetsAppCleanClass);
        statusBar->setObjectName("statusBar");
        QtWidgetsAppCleanClass->setStatusBar(statusBar);

        retranslateUi(QtWidgetsAppCleanClass);

        QMetaObject::connectSlotsByName(QtWidgetsAppCleanClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsAppCleanClass)
    {
        QtWidgetsAppCleanClass->setWindowTitle(QCoreApplication::translate("QtWidgetsAppCleanClass", "QtWidgetsAppClean", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsAppCleanClass: public Ui_QtWidgetsAppCleanClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPCLEAN_H
