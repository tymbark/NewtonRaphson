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
#include <QtWidgets/QGroupBox>
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
    QTextEdit *textEdit_x;
    QTextEdit *textEdit_mit;
    QTextEdit *textEdit_eps;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit_result;
    QTextEdit *textEdit_it;
    QTextEdit *textEdit_fatx;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_image;
    QLabel *label_check;
    QGroupBox *groupBox;
    QRadioButton *radioButton_eq1;
    QRadioButton *radioButton_eq2;
    QRadioButton *radioButton_eq0;
    QPushButton *pushButton_fill;
    QTextEdit *textEdit_x_2;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_normal;
    QRadioButton *radioButton_interval;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(533, 285);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_title = new QLabel(centralWidget);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(10, 0, 271, 31));
        button_solve = new QPushButton(centralWidget);
        button_solve->setObjectName(QStringLiteral("button_solve"));
        button_solve->setGeometry(QRect(370, 250, 151, 27));
        textEdit_x = new QTextEdit(centralWidget);
        textEdit_x->setObjectName(QStringLiteral("textEdit_x"));
        textEdit_x->setGeometry(QRect(40, 130, 101, 31));
        textEdit_mit = new QTextEdit(centralWidget);
        textEdit_mit->setObjectName(QStringLiteral("textEdit_mit"));
        textEdit_mit->setGeometry(QRect(40, 170, 151, 31));
        textEdit_eps = new QTextEdit(centralWidget);
        textEdit_eps->setObjectName(QStringLiteral("textEdit_eps"));
        textEdit_eps->setGeometry(QRect(40, 210, 151, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 130, 21, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 210, 21, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 170, 21, 20));
        textEdit_result = new QTextEdit(centralWidget);
        textEdit_result->setObjectName(QStringLiteral("textEdit_result"));
        textEdit_result->setGeometry(QRect(370, 130, 151, 31));
        textEdit_it = new QTextEdit(centralWidget);
        textEdit_it->setObjectName(QStringLiteral("textEdit_it"));
        textEdit_it->setGeometry(QRect(370, 210, 151, 31));
        textEdit_fatx = new QTextEdit(centralWidget);
        textEdit_fatx->setObjectName(QStringLiteral("textEdit_fatx"));
        textEdit_fatx->setGeometry(QRect(370, 170, 151, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(280, 130, 91, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(280, 170, 91, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(300, 210, 71, 16));
        label_image = new QLabel(centralWidget);
        label_image->setObjectName(QStringLiteral("label_image"));
        label_image->setGeometry(QRect(230, 40, 231, 41));
        label_check = new QLabel(centralWidget);
        label_check->setObjectName(QStringLiteral("label_check"));
        label_check->setGeometry(QRect(70, 90, 411, 21));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(110, 40, 120, 80));
        radioButton_eq1 = new QRadioButton(groupBox);
        radioButton_eq1->setObjectName(QStringLiteral("radioButton_eq1"));
        radioButton_eq1->setGeometry(QRect(0, 20, 92, 21));
        radioButton_eq2 = new QRadioButton(groupBox);
        radioButton_eq2->setObjectName(QStringLiteral("radioButton_eq2"));
        radioButton_eq2->setGeometry(QRect(0, 40, 92, 21));
        radioButton_eq0 = new QRadioButton(groupBox);
        radioButton_eq0->setObjectName(QStringLiteral("radioButton_eq0"));
        radioButton_eq0->setGeometry(QRect(0, 0, 92, 21));
        radioButton_eq1->raise();
        radioButton_eq2->raise();
        radioButton_eq0->raise();
        pushButton_fill = new QPushButton(centralWidget);
        pushButton_fill->setObjectName(QStringLiteral("pushButton_fill"));
        pushButton_fill->setGeometry(QRect(40, 250, 151, 27));
        textEdit_x_2 = new QTextEdit(centralWidget);
        textEdit_x_2->setObjectName(QStringLiteral("textEdit_x_2"));
        textEdit_x_2->setGeometry(QRect(150, 130, 101, 31));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 30, 120, 80));
        radioButton_normal = new QRadioButton(groupBox_2);
        radioButton_normal->setObjectName(QStringLiteral("radioButton_normal"));
        radioButton_normal->setGeometry(QRect(0, 10, 92, 21));
        radioButton_interval = new QRadioButton(groupBox_2);
        radioButton_interval->setObjectName(QStringLiteral("radioButton_interval"));
        radioButton_interval->setGeometry(QRect(0, 30, 92, 21));
        radioButton_normal->raise();
        radioButton_interval->raise();
        radioButton_normal->raise();
        radioButton_interval->raise();
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_title->setText(QApplication::translate("MainWindow", "Damian Michalak 109789 Newton - Raphson method", 0));
        button_solve->setText(QApplication::translate("MainWindow", "Solve", 0));
        label->setText(QApplication::translate("MainWindow", "x:", 0));
        label_2->setText(QApplication::translate("MainWindow", "eps:", 0));
        label_3->setText(QApplication::translate("MainWindow", "mit:", 0));
        label_4->setText(QApplication::translate("MainWindow", "aprox root value:", 0));
        label_5->setText(QApplication::translate("MainWindow", "f(x) value at root:", 0));
        label_6->setText(QApplication::translate("MainWindow", "no iterations:", 0));
        label_image->setText(QApplication::translate("MainWindow", "EQUATION", 0));
        label_check->setText(QString());
        groupBox->setTitle(QString());
        radioButton_eq1->setText(QApplication::translate("MainWindow", "equation 2", 0));
        radioButton_eq2->setText(QApplication::translate("MainWindow", "equation 3", 0));
        radioButton_eq0->setText(QApplication::translate("MainWindow", "equation 1", 0));
        pushButton_fill->setText(QApplication::translate("MainWindow", "Fill", 0));
        groupBox_2->setTitle(QString());
        radioButton_normal->setText(QApplication::translate("MainWindow", "normal", 0));
        radioButton_interval->setText(QApplication::translate("MainWindow", "interval", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
