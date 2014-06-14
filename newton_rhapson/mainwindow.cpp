#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    eq = new Equation(0);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete eq;
}


void MainWindow::on_button_solve_clicked()
{
    printf("button solve clicked \n");
    //eq->newtonRaphson();
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
