#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "JKuna/jkuna.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	QString apiKey = "";
	QString secretKey = "";

private:
	Ui::MainWindow *ui;
	JKuna *Kuna;
};

#endif // MAINWINDOW_H
