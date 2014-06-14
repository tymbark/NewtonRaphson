#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton_eq1->setChecked(true);
    ui->radioButton_normal->setChecked(true);
    on_radioButton_normal_clicked();
    on_radioButton_eq1_clicked();
    eq = new Equation(1);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete eq;
}


void MainWindow::on_button_solve_clicked(){

    if(check() == 0) return;

    if(ui->radioButton_eq1->isChecked()) eq->id = 1;
    if(ui->radioButton_eq2->isChecked()) eq->id = 2;
    if(ui->radioButton_eq3->isChecked()) eq->id = 3;
    //if(ui->radioButton_interval->isChecked()) //TODO
    //if(ui->radioButton_normal->isChecked()) // TODO

    string x = (ui->textEdit_x->toPlainText()).toStdString();
    string eps = (ui->textEdit_eps->toPlainText()).toStdString();
    string mit = (ui->textEdit_mit->toPlainText()).toStdString();

    istringstream x_in(x);
    x_in >> eq->x;

    istringstream eps_in(eps);
    eps_in >> eq->eps;

    istringstream mit_in(mit);
    mit_in >> eq->mit;

    eq->newtonRaphson();

}


void MainWindow::on_radioButton_eq1_clicked()
{
    QPixmap pix("eq1.png");
    ui->label_image->setPixmap(pix);
}

void MainWindow::on_radioButton_eq2_clicked()
{
    QPixmap pix("eq2.png");
    ui->label_image->setPixmap(pix);
}

int MainWindow::check(){
    int result = 1;
    if(ui->textEdit_x->toPlainText().isEmpty()){
        ui->textEdit_x->setText("INVALID");
        result = 0;
    }
    if(ui->textEdit_mit->toPlainText().isEmpty()){
        ui->textEdit_mit->setText("INVALID");
        result = 0;
    }
    if(ui->textEdit_eps->toPlainText().isEmpty()){
        ui->textEdit_eps->setText("INVALID");
        result = 0;
    }
    return result;
}

void MainWindow::on_radioButton_interval_clicked()
{

}

void MainWindow::on_radioButton_normal_clicked()
{

}
