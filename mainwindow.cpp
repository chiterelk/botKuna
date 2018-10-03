#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	Kuna = new JKuna(this);

	//Kuna->getTicker("xemuah");
	//Kuna->getMembers(apiKey,secretKey);
	Kuna->getOrders(apiKey,secretKey,"xemuah");
}

MainWindow::~MainWindow()
{
	delete ui;
}
