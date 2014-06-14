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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_title;
    QPushButton *button_add;
    QPushButton *button_solve;
    QLabel *label_equation;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(289, 106);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_title = new QLabel(centralWidget);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(10, 0, 271, 31));
        button_add = new QPushButton(centralWidget);
        button_add->setObjectName(QStringLiteral("button_add"));
        button_add->setGeometry(QRect(10, 70, 85, 27));
        button_solve = new QPushButton(centralWidget);
        button_solve->setObjectName(QStringLiteral("button_solve"));
        button_solve->setGeometry(QRect(200, 70, 85, 27));
        label_equation = new QLabel(centralWidget);
        label_equation->setObjectName(QStringLiteral("label_equation"));
        label_equation->setGeometry(QRect(40, 40, 231, 16));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        label_equation->setFont(font);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_title->setText(QApplication::translate("MainWindow", "Damian Michalak 109789 Newton - Raphson method", 0));
#ifndef QT_NO_TOOLTIP
        button_add->setToolTip(QApplication::translate("MainWindow", "add new equation to solve", 0));
#endif // QT_NO_TOOLTIP
        button_add->setText(QApplication::translate("MainWindow", "Add Equation", 0));
        button_solve->setText(QApplication::translate("MainWindow", "Solve", 0));
        label_equation->setText(QApplication::translate("MainWindow", "no equation to solve", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
