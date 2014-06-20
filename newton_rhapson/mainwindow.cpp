    #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    eq = new Equation(0);

    ui->setupUi(this);
    ui->radioButton_eq0->setChecked(true);
    ui->radioButton_normal->setChecked(true);
    on_radioButton_normal_clicked();
    on_radioButton_eq0_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete eq;
}


void MainWindow::on_button_solve_clicked(){

    if(check() == 0) return;

    //if(ui->radioButton_eq1->isChecked()) eq->id = 1;
    //if(ui->radioButton_eq2->isChecked()) eq->id = 2;
    //if(ui->radioButton_eq3->isChecked()) eq->id = 3;
    //if(ui->radioButton_interval->isChecked()) //TODO
    //if(ui->radioButton_normal->isChecked()) // TODO

    eq->x = qstrToLD(ui->textEdit_x->toPlainText());
    eq->eps = qstrToLD(ui->textEdit_eps->toPlainText());
    eq->mit = qstrToLD(ui->textEdit_mit->toPlainText());

    eq->newtonRaphson();

    ui->textEdit_result->setText(LDtoQstr(eq->result));
    ui->textEdit_fatx->setText(LDtoQstr(eq->fatx));
    ui->textEdit_it->setText(LDtoQstr(eq->it));
}


void MainWindow::on_radioButton_eq1_clicked()
{
    eq->id = 1;
    QPixmap pix("eq1.png");
    ui->label_image->setPixmap(pix);
}

void MainWindow::on_radioButton_eq2_clicked()
{
    eq->id = 2;
    QPixmap pix("eq2.png");
    ui->label_image->setPixmap(pix);
}

void MainWindow::on_radioButton_eq0_clicked()
{
    eq->id = 0;
    QPixmap pix("eq0.png");
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

long double MainWindow::qstrToLD(QString input){
    long double result;

    string str = input.toStdString();
    istringstream longD_stream(str);
    longD_stream >> result;

    return result;
}

QString MainWindow::LDtoQstr(long double input){
    QString result;
    stringstream string_stream;
    string_stream << input;
    result = result.fromStdString(string_stream.str());
    return result;
}

void MainWindow::on_radioButton_interval_clicked(){
    ui->textEdit_x_2->setEnabled(true);
    ui->textEdit_x_2->setText("");
    QApplication::processEvents();
    cout << "interval clicked" <<  "\n";
}

void MainWindow::on_radioButton_normal_clicked(){
    ui->textEdit_x_2->setText("UNAVAILABLE");
    ui->textEdit_x_2->setEnabled(false);
    QApplication::processEvents();
    cout << "interval unclicked" <<  "\n";
}

void MainWindow::on_pushButton_fill_clicked()
{
    if(eq->id == 0){
        ui->textEdit_x->setText("-1");
        ui->textEdit_mit->setText("10");
        ui->textEdit_eps->setText("0.0000000000000001");
    }else if(eq->id == 1){
        ui->textEdit_x->setText("-2.2");
        ui->textEdit_mit->setText("10");
        ui->textEdit_eps->setText("0.0000000000000001");
    } else if(eq->id == 2){
        ui->textEdit_x->setText("0.6");
        ui->textEdit_mit->setText("20");
        ui->textEdit_eps->setText("0.0000000000000001");
    }
}

