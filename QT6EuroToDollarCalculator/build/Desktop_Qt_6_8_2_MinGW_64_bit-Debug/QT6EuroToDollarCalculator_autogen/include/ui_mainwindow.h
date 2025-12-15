/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLineEdit *txt_euro;
    QLineEdit *txt_dollar;
    QLabel *label;
    QPushButton *btn_rechnen;
    QPushButton *btn_ende;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(228, 146);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 60, 37, 12));
        txt_euro = new QLineEdit(centralwidget);
        txt_euro->setObjectName("txt_euro");
        txt_euro->setGeometry(QRect(90, 30, 113, 20));
        txt_dollar = new QLineEdit(centralwidget);
        txt_dollar->setObjectName("txt_dollar");
        txt_dollar->setEnabled(false);
        txt_dollar->setGeometry(QRect(90, 60, 113, 20));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 37, 12));
        btn_rechnen = new QPushButton(centralwidget);
        btn_rechnen->setObjectName("btn_rechnen");
        btn_rechnen->setEnabled(false);
        btn_rechnen->setGeometry(QRect(40, 90, 80, 18));
        btn_ende = new QPushButton(centralwidget);
        btn_ende->setObjectName("btn_ende");
        btn_ende->setGeometry(QRect(120, 90, 80, 18));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Euro2Dollar", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Dollar:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Euro:", nullptr));
        btn_rechnen->setText(QCoreApplication::translate("MainWindow", "Rechnen", nullptr));
        btn_ende->setText(QCoreApplication::translate("MainWindow", "Beenden", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
