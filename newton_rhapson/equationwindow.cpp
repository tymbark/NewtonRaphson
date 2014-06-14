#include "equationwindow.h"
#include "ui_equationwindow.h"
#include <cstdio>

EquationWindow::EquationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EquationWindow)
{
    ui->setupUi(this);
}

EquationWindow::~EquationWindow()
{
    delete ui;
}

void EquationWindow::setEquation(Equation * _equation){
    equation = _equation;
}

void EquationWindow::on_button_done_clicked()
{
    
    close();
}

