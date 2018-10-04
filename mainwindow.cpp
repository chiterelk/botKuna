#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	Kuna = new JKuna(this);

    //Kuna->getOrders(apiKey,secretKey,"xemuah");
    //Kuna->getMembers(apiKey,secretKey);
    //Kuna->openBuyOrders(apiKey,secretKey,"xemuah",20.0841,2.97);
    //Kuna->deleteOrder(apiKey,secretKey,"24747248");
    //Kuna->getDepth("xemuah");
}

MainWindow::~MainWindow()
{
	delete ui;
}
