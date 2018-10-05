#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	logIn = new LogInWondow(this);
	logIn->show();
	Kuna = new JKuna(this);


	//Kuna->getOrders(apiKey,secretKey,"xemuah");
	//Kuna->getMembers(apiKey,secretKey);
	//Kuna->openSellOrders(apiKey,secretKey,"xemuah",5,5);
	//Kuna->deleteOrder(apiKey,secretKey,"24978138");
	//connect(Kuna,&JKuna::gotTrades,this,&MainWindow::gotTrades);
	//connect(Kuna,&JKuna::gotOrders,this,&MainWindow::gotOrders);
	//Kuna->getTrades("xemuah");
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::gotTicker(JTicker _ticker)
{

}

void MainWindow::gotDepth(QList<QList<JOrderOfDepth> > _depth)
{

}

void MainWindow::gotTrades(QList<JOrderOfDepth> _trades)
{

}

void MainWindow::gotMembers(QList<JBalance> _wallet)
{

}

void MainWindow::gotOrders(QList<JActiveOrders> _activeOrders)
{

}
