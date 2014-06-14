#include <QStandardItemModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <sstream>
#include <QMessageBox>
#include <QDebug>

#include "cspl.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(buttonBox(QAbstractButton*)));
}


void MainWindow::calculateInterval() {
	int n = ui->spinBox->value();
	QStringList xs = ui->plainTextEdit->toPlainText().split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
	if (xs.count() < n) {
		QMessageBox::information(this, "Error", "Za malo wezlow!");
		return;
	}
	QStringList fs = ui->plainTextEdit_2->toPlainText().split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
	if (fs.count() < n) {
		QMessageBox::information(this, "Error", "Za malo wartosci!");
		return;
	}

	ui->tableWidget->setColumnCount(4);
	ui->tableWidget->setRowCount(n-1);

	QStringList sl;
	sl.append("0");
	sl.append("1");
	sl.append("2");
	sl.append("3");
	ui->tableWidget->setHorizontalHeaderLabels(sl);
	for (int i=4; i<n; i++) {
		sl.append(QString::number(i, 10));
	}
	ui->tableWidget->setVerticalHeaderLabels(sl);


	interval x[n], f[n], f1x0 = interval(ui->doubleSpinBox->value(), ui->doubleSpinBox_3->value()), f1xn = interval(ui->doubleSpinBox_2->value(), ui->doubleSpinBox_4->value()), xx = interval(ui->doubleSpinBox_5->value(), ui->doubleSpinBox_6->value());
	int st1, st2;
	interval res[n][4];

	qDebug() << xs.count();
	for (int i=0; i<n; i++) {
		QStringList twos;
		twos = xs[i].split(';');
		if (twos.count() != 2) {
			QMessageBox::information(this, "Error", "Bledne dane!");
			return;
		}
		x[i] = interval(twos[0].toStdString(), twos[1].toStdString());
		twos = fs[i].split(';');
		if (twos.count() != 2) {
			QMessageBox::information(this, "Error", "Bledne dane!");
			return;
		}
		f[i] = interval(twos[0].toStdString(), twos[1].toStdString());
	}

	interval val;
	try {
		iclampedsplinecoeffns(n-1, x, f, f1x0, f1xn, res, st1);
		val = iclampedsplinevalue(n-1, x, f, f1x0, f1xn, xx, st2);
	} catch (...) {
		QMessageBox::information(this, "Error", "Runtime error!");
		return;
	}

	for (int i=0; i<n-1; i++) {
		for (int j=0; j<4; j++) {
			QTableWidgetItem* item = new QTableWidgetItem();
			stringstream ss;
			ss << res[i][j];
			item->setText(ss.str().c_str());
			ui->tableWidget->setItem(i,j,item);
		}
	}

	stringstream ss;
	ss << val;
	ui->label_7->setText(ss.str().c_str());

	ui->label_8->setText("st1 = " + QString::number(st1,10) + ", st2 = " + QString::number(st2,10));

}


void MainWindow::calculateIntervalSingle() {
	int n = ui->spinBox->value();
	QStringList xs = ui->plainTextEdit->toPlainText().split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
	if (xs.count() < n) {
		QMessageBox::information(this, "Error", "Za malo wezlow!");
		return;
	}
	QStringList fs = ui->plainTextEdit_2->toPlainText().split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
	if (fs.count() < n) {
		QMessageBox::information(this, "Error", "Za malo wartosci!");
		return;
	}

	ui->tableWidget->setColumnCount(4);
	ui->tableWidget->setRowCount(n-1);

	QStringList sl;
	sl.append("0");
	sl.append("1");
	sl.append("2");
	sl.append("3");
	ui->tableWidget->setHorizontalHeaderLabels(sl);
	for (int i=4; i<n; i++) {
		sl.append(QString::number(i, 10));
	}
	ui->tableWidget->setVerticalHeaderLabels(sl);


	interval x[n], f[n], f1x0 = interval(ui->doubleSpinBox->value()), f1xn = interval(ui->doubleSpinBox_2->value()), xx = interval(ui->doubleSpinBox_5->value());
	int st1, st2;
	interval res[n][4];

	qDebug() << xs.count();
	for (int i=0; i<n; i++) {
		x[i] = interval(xs[i].toStdString());
		f[i] = interval(fs[i].toStdString());
	}

	interval val;
	try {
		iclampedsplinecoeffns(n-1, x, f, f1x0, f1xn, res, st1);
		val = iclampedsplinevalue(n-1, x, f, f1x0, f1xn, xx, st2);
	} catch (...) {
		QMessageBox::information(this, "Error", "Runtime error!");
		return;
	}

	for (int i=0; i<n-1; i++) {
		for (int j=0; j<4; j++) {
			QTableWidgetItem* item = new QTableWidgetItem();
			stringstream ss;
			ss << res[i][j];
			item->setText(ss.str().c_str());
			ui->tableWidget->setItem(i,j,item);
		}
	}

	stringstream ss;
	ss << val;
	ui->label_7->setText(ss.str().c_str());

	ui->label_8->setText("st1 = " + QString::number(st1,10) + ", st2 = " + QString::number(st2,10));

}


void MainWindow::calculateReal() {
	int n = ui->spinBox->value();
	QStringList xs = ui->plainTextEdit->toPlainText().split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
	if (xs.count() < n) {
		QMessageBox::information(this, "Error", "Za malo wezlow!");
		return;
	}
	QStringList fs = ui->plainTextEdit_2->toPlainText().split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
	if (fs.count() < n) {
		QMessageBox::information(this, "Error", "Za malo wartosci!");
		return;
	}

	ui->tableWidget->setColumnCount(4);
	ui->tableWidget->setRowCount(n-1);

	QStringList sl;
	sl.append("0");
	sl.append("1");
	sl.append("2");
	sl.append("3");
	ui->tableWidget->setHorizontalHeaderLabels(sl);
	for (int i=4; i<n; i++) {
		sl.append(QString::number(i, 10));
	}
	ui->tableWidget->setVerticalHeaderLabels(sl);


	__float128 x[n], f[n], f1x0 = ui->doubleSpinBox->value(), f1xn = ui->doubleSpinBox_2->value(), xx = ui->doubleSpinBox_5->value();
	int st1, st2;
	__float128 res[n][4];

	qDebug() << xs.count();
	for (int i=0; i<n; i++) {
		x[i] = strtoflt128(xs[i].toStdString().c_str(), NULL);
		f[i] = strtoflt128(fs[i].toStdString().c_str(), NULL);
	}

	__float128 val;
	try {
		clampedsplinecoeffns(n-1, x, f, f1x0, f1xn, res, st1);
		val = clampedsplinevalue(n-1, x, f, f1x0, f1xn, xx, st2);
	} catch (...) {
		QMessageBox::information(this, "Error", "Runtime error!");
		return;
	}


	for (int i=0; i<n-1; i++) {
		for (int j=0; j<4; j++) {
			QTableWidgetItem* item = new QTableWidgetItem();
			stringstream ss;
			ss << res[i][j];
			item->setText(ss.str().c_str());
			ui->tableWidget->setItem(i,j,item);
		}
	}

	stringstream ss;
	ss << val;
	ui->label_7->setText(ss.str().c_str());

	ui->label_8->setText("st1 = " + QString::number(st1,10) + ", st2 = " + QString::number(st2,10));

}

void MainWindow::buttonBox(QAbstractButton* btn) {
	QDialogButtonBox::StandardButton stdButton = ui->buttonBox->standardButton(btn);
	switch (stdButton) {
		case QDialogButtonBox::Apply:
			if (ui->radioButton->isChecked()) {
				calculateReal();
			} else if (ui->radioButton_3->isChecked()) {
				calculateIntervalSingle();
			} else {
				calculateInterval();
			}
			break;
		case QDialogButtonBox::Reset:
			ui->tableWidget->setColumnCount(0);
			ui->tableWidget->setRowCount(0);
			ui->doubleSpinBox->setValue(0.0);
			ui->doubleSpinBox_2->setValue(0.0);
			ui->doubleSpinBox_3->setValue(0.0);
			ui->doubleSpinBox_4->setValue(0.0);
			ui->doubleSpinBox_5->setValue(0.0);
			ui->doubleSpinBox_6->setValue(0.0);
			ui->spinBox->setValue(0);
			ui->plainTextEdit->clear();
			ui->plainTextEdit_2->clear();
			ui->radioButton->setChecked(true);
			ui->label_7->setText("");
			ui->label_8->setText("");
			break;
		default:
			break;
	}
}

MainWindow::~MainWindow()
{
	delete ui;
}
