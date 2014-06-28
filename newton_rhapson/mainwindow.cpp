    #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    eq = new Equation(0);
    eq_i = new Equation_Interval(0);

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

    if(ui->radioButton_interval->isChecked()){
        eq_i->x = IntervalArithmetic::IntRead((ui->textEdit_x->toPlainText().toStdString()));
        eq_i->eps = IntervalArithmetic::IntRead((ui->textEdit_eps->toPlainText().toStdString()));
        //eq_i = IntervalArithmetic::IntRead((ui->textEdit_x->toPlainText().toStdString());
        //eq_i->x.a = qstrToLD();
        //eq_i->x.b = qstrToLD(ui->textEdit_x_2->toPlainText());
           // string str = input.toStdString();
          //  istringstream longD_stream(str);
        //eq_i->eps.a = qstrToLD(ui->textEdit_eps->toPlainText());
        //eq_i->eps.b = qstrToLD(ui->textEdit_eps_2->toPlainText());

        eq_i->mit = qstrToLD(ui->textEdit_mit->toPlainText());

        eq_i->newtonRaphson();

        ui->textEdit_result->setText(LDtoQstr(eq_i->result.a));
        ui->textEdit_result_2->setText(LDtoQstr(eq_i->result.b));
        ui->textEdit_fatx->setText(LDtoQstr(eq_i->fatx.a));
        ui->textEdit_fatx_2->setText(LDtoQstr(eq_i->fatx.b));
        ui->textEdit_it->setText(LDtoQstr(eq_i->it));

    }else if(ui->radioButton_normal->isChecked()){

        eq->x = qstrToLD(ui->textEdit_x->toPlainText());
        eq->eps = qstrToLD(ui->textEdit_eps->toPlainText());
        eq->mit = qstrToLD(ui->textEdit_mit->toPlainText());

        eq->newtonRaphson();

        ui->textEdit_result->setText(LDtoQstr(eq->result));
        ui->textEdit_fatx->setText(LDtoQstr(eq->fatx));
        ui->textEdit_it->setText(LDtoQstr(eq->it));
    }
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
    ui->textEdit_fatx_2->setText("");
    ui->textEdit_fatx_2->setEnabled(true);
    ui->textEdit_result_2->setText("");
    ui->textEdit_result_2->setEnabled(true);
    ui->textEdit_eps_2->setText("");
    ui->textEdit_eps_2->setEnabled(true);
    QApplication::processEvents();
    cout << "interval clicked" <<  "\n";
}

void MainWindow::on_radioButton_normal_clicked(){
    ui->textEdit_x_2->setText("UNAVAILABLE");
    ui->textEdit_x_2->setEnabled(false);
    ui->textEdit_fatx_2->setText("UNAVAILABLE");
    ui->textEdit_fatx_2->setEnabled(false);
    ui->textEdit_result_2->setText("UNAVAILABLE");
    ui->textEdit_result_2->setEnabled(false);
    ui->textEdit_eps_2->setText("UNAVAILABLE");
    ui->textEdit_eps_2->setEnabled(false);
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

