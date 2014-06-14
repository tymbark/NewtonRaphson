#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstdio>
#include <string>
#include "equation.h"
#include "equationwindow.h"

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

private:
    Ui::MainWindow *ui;
    Equation * eq;
    bool equationPrepared;
};

#endif // MAINWINDOW_H
