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
    connect(logIn,&LogInWondow::loginedIn,this,&MainWindow::loginedIn);
    ui->groupBox_2->setHidden(1);
    ui->groupBox_3->setHidden(1);
    ui->groupBox_4->setHidden(1);
    ui->groupBox_5->setHidden(1);
    ui->groupBox_6->setHidden(1);
    ui->groupBox_7->setHidden(1);
    ui->groupBox_8->setHidden(1);
    connect(timerGetTicker,&QTimer::timeout,this,&MainWindow::getTicker);
    connect(Kuna,&JKuna::gotTicker,this,&MainWindow::gotTicker);

    connect(Kuna,&JKuna::gotMembers,this,&MainWindow::gotMembers);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::gotTicker(JTicker _ticker)
{
    ui->labelAsk->setText(QString::number(_ticker.getSell()));
    ui->labelBid->setText(QString::number(_ticker.getBuy()));
    ui->labelSpread->setText(QString::number(_ticker.getSpread()*100)+"%");
}

void MainWindow::gotDepth(QList<QList<JOrderOfDepth> > _depth)
{

}

void MainWindow::gotTrades(QList<JOrderOfDepth> _trades)
{

}

void MainWindow::gotMembers(QList<JBalance> _wallet)
{
//

}

void MainWindow::gotOrders(QList<JActiveOrders> _activeOrders)
{

}

void MainWindow::loginedIn(QString _apiKey, QString _secretKey)
{
    apiKey_ = _apiKey;
    secretKey_ = _secretKey;
    this->show();
    logIn->close();
}

void MainWindow::on_pushButtonStart_clicked()
{
    perekritie = ui->lineEditPerekritie_2->text().toDouble();
    numberOrders = ui->lineEditNumberOrder->text().toInt();
    martingeil = ui->lineEditMartingeil->text().toDouble();
    procent = ui->lineEditProcent_2->text().toDouble();
    depozit = ui->lineEdit_deposit_2->text().toDouble();
    minSpread = ui->lineEditMinSpread->text().toDouble();
    process = 1;
    market = ui->comboBox->currentText();
    ui->groupBox->setHidden(1);
    ui->groupBox_2->setHidden(0);
    ui->groupBox_3->setHidden(0);
    ui->groupBox_4->setHidden(0);
    ui->groupBox_5->setHidden(0);
    ui->groupBox_6->setHidden(0);
    ui->groupBox_7->setHidden(0);
    ui->groupBox_8->setHidden(0);
    getTicker();
    timerGetTicker->start(1000);
    Kuna->getMembers(apiKey_,secretKey_);

}

void MainWindow::on_pushButtonClose_clicked()
{
    QApplication::closeAllWindows();
}

void MainWindow::getTicker()
{
    Kuna->getTicker(market);
}
