#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT
		
	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
		
	public slots:
			void buttonBox(QAbstractButton* btn);

	private:
		Ui::MainWindow *ui;
		void calculateReal();
		void calculateInterval();
		void calculateIntervalSingle();
};

#endif // MAINWINDOW_H
