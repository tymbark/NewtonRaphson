#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstdio>
#include <string>
#include "equation.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_button_solve_clicked();
    void on_radioButton_eq1_clicked();
    void on_radioButton_eq2_clicked();
    void on_radioButton_interval_clicked();
    void on_radioButton_normal_clicked();
    void on_pushButton_fill_clicked();

    void on_radioButton_eq0_clicked();

private:
    Ui::MainWindow *ui;
    Equation * eq;
    int check();
    long double qstrToLD(QString _input);
    QString LDtoQstr(long double input);

};

#endif // MAINWINDOW_H
