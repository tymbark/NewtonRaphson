/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_title;
    QPushButton *button_solve;
    QRadioButton *radioButton_normal;
    QRadioButton *radioButton_interval;
    QRadioButton *radioButton_eq1;
    QRadioButton *radioButton_eq2;
    QRadioButton *radioButton_eq3;
    QTextEdit *textEdit_x;
    QTextEdit *textEdit_mit;
    QTextEdit *textEdit_eps;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit_newton;
    QTextEdit *textEdit_it;
    QTextEdit *textEdit_st;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_image;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(475, 280);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_title = new QLabel(centralWidget);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(10, 0, 271, 31));
        button_solve = new QPushButton(centralWidget);
        button_solve->setObjectName(QStringLiteral("button_solve"));
        button_solve->setGeometry(QRect(20, 240, 431, 27));
        radioButton_normal = new QRadioButton(centralWidget);
        radioButton_normal->setObjectName(QStringLiteral("radioButton_normal"));
        radioButton_normal->setGeometry(QRect(20, 40, 92, 21));
        radioButton_interval = new QRadioButton(centralWidget);
        radioButton_interval->setObjectName(QStringLiteral("radioButton_interval"));
        radioButton_interval->setGeometry(QRect(20, 60, 92, 21));
        radioButton_eq1 = new QRadioButton(centralWidget);
        radioButton_eq1->setObjectName(QStringLiteral("radioButton_eq1"));
        radioButton_eq1->setGeometry(QRect(120, 40, 92, 21));
        radioButton_eq2 = new QRadioButton(centralWidget);
        radioButton_eq2->setObjectName(QStringLiteral("radioButton_eq2"));
        radioButton_eq2->setGeometry(QRect(120, 60, 92, 21));
        radioButton_eq3 = new QRadioButton(centralWidget);
        radioButton_eq3->setObjectName(QStringLiteral("radioButton_eq3"));
        radioButton_eq3->setGeometry(QRect(120, 80, 92, 21));
        textEdit_x = new QTextEdit(centralWidget);
        textEdit_x->setObjectName(QStringLiteral("textEdit_x"));
        textEdit_x->setGeometry(QRect(40, 110, 151, 31));
        textEdit_mit = new QTextEdit(centralWidget);
        textEdit_mit->setObjectName(QStringLiteral("textEdit_mit"));
        textEdit_mit->setGeometry(QRect(40, 150, 151, 31));
        textEdit_eps = new QTextEdit(centralWidget);
        textEdit_eps->setObjectName(QStringLiteral("textEdit_eps"));
        textEdit_eps->setGeometry(QRect(40, 190, 151, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 110, 21, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 190, 21, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 150, 21, 20));
        textEdit_newton = new QTextEdit(centralWidget);
        textEdit_newton->setObjectName(QStringLiteral("textEdit_newton"));
        textEdit_newton->setGeometry(QRect(300, 110, 151, 31));
        textEdit_it = new QTextEdit(centralWidget);
        textEdit_it->setObjectName(QStringLiteral("textEdit_it"));
        textEdit_it->setGeometry(QRect(300, 150, 151, 31));
        textEdit_st = new QTextEdit(centralWidget);
        textEdit_st->setObjectName(QStringLiteral("textEdit_st"));
        textEdit_st->setGeometry(QRect(300, 190, 151, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(230, 110, 71, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(230, 150, 71, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 190, 71, 16));
        label_image = new QLabel(centralWidget);
        label_image->setObjectName(QStringLiteral("label_image"));
        label_image->setGeometry(QRect(230, 40, 231, 41));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_title->setText(QApplication::translate("MainWindow", "Damian Michalak 109789 Newton - Raphson method", 0));
        button_solve->setText(QApplication::translate("MainWindow", "Solve", 0));
        radioButton_normal->setText(QApplication::translate("MainWindow", "normal", 0));
        radioButton_interval->setText(QApplication::translate("MainWindow", "interval", 0));
        radioButton_eq1->setText(QApplication::translate("MainWindow", "equation 1", 0));
        radioButton_eq2->setText(QApplication::translate("MainWindow", "equation 2", 0));
        radioButton_eq3->setText(QApplication::translate("MainWindow", "equation 3", 0));
        label->setText(QApplication::translate("MainWindow", "x:", 0));
        label_2->setText(QApplication::translate("MainWindow", "eps:", 0));
        label_3->setText(QApplication::translate("MainWindow", "mit:", 0));
        label_4->setText(QApplication::translate("MainWindow", "aprox root:", 0));
        label_5->setText(QApplication::translate("MainWindow", "function val:", 0));
        label_6->setText(QApplication::translate("MainWindow", "no iterations:", 0));
        label_image->setText(QApplication::translate("MainWindow", "EQUATION", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
