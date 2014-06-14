#ifndef EQUATIONWINDOW_H
#define EQUATIONWINDOW_H

#include <QDialog>
#include <string>
#include "equation.h"

namespace Ui {
class EquationWindow;
}

class EquationWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit EquationWindow(QWidget *parent = 0);
    ~EquationWindow();
    void setEquation(Equation * _equation);
    
private slots:
    void on_button_done_clicked();

private:
    Ui::EquationWindow *ui;
    Equation * equation;
};

#endif // EQUATIONWINDOW_H
