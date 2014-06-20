/********************************************************************************
** Form generated from reading UI file 'equationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUATIONWINDOW_H
#define UI_EQUATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_EquationWindow
{
public:
    QPushButton *button_done;
    QLabel *label_eq1;
    QLabel *label_eq1_2;
    QComboBox *comboBox;
    QTextEdit *textEdit;
    QLabel *label;
    QTextEdit *textEdit_2;

    void setupUi(QDialog *EquationWindow)
    {
        if (EquationWindow->objectName().isEmpty())
            EquationWindow->setObjectName(QStringLiteral("EquationWindow"));
        EquationWindow->resize(574, 155);
        button_done = new QPushButton(EquationWindow);
        button_done->setObjectName(QStringLiteral("button_done"));
        button_done->setGeometry(QRect(480, 120, 85, 27));
        label_eq1 = new QLabel(EquationWindow);
        label_eq1->setObjectName(QStringLiteral("label_eq1"));
        label_eq1->setGeometry(QRect(10, 90, 49, 21));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        label_eq1->setFont(font);
        label_eq1_2 = new QLabel(EquationWindow);
        label_eq1_2->setObjectName(QStringLiteral("label_eq1_2"));
        label_eq1_2->setGeometry(QRect(60, 90, 501, 21));
        label_eq1_2->setFont(font);
        comboBox = new QComboBox(EquationWindow);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(130, 10, 101, 24));
        textEdit = new QTextEdit(EquationWindow);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(60, 40, 41, 31));
        label = new QLabel(EquationWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 61, 16));
        textEdit_2 = new QTextEdit(EquationWindow);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(130, 40, 101, 31));

        retranslateUi(EquationWindow);

        QMetaObject::connectSlotsByName(EquationWindow);
    } // setupUi

    void retranslateUi(QDialog *EquationWindow)
    {
        EquationWindow->setWindowTitle(QApplication::translate("EquationWindow", "Dialog", 0));
        button_done->setText(QApplication::translate("EquationWindow", "Done", 0));
        label_eq1->setText(QApplication::translate("EquationWindow", "f(x) = ", 0));
        label_eq1_2->setText(QApplication::translate("EquationWindow", "empty", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("EquationWindow", "power(x)", 0)
         << QApplication::translate("EquationWindow", "sin(x)", 0)
         << QApplication::translate("EquationWindow", "cos(x)", 0)
        );
        label->setText(QApplication::translate("EquationWindow", "sign (+ or -)", 0));
    } // retranslateUi

};

namespace Ui {
    class EquationWindow: public Ui_EquationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUATIONWINDOW_H
