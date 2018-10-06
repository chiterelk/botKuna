#include "loginwondow.h"
#include "ui_loginwondow.h"
#include <QPalette>

LogInWondow::LogInWondow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::LogInWondow)
{
	ui->setupUi(this);
	ui->progressBar->setHidden(1);
	logInKuna = new JKuna(this);
	timer = new QTimer(this);
	connect(timer,&QTimer::timeout,this,&LogInWondow::tact);

}

LogInWondow::~LogInWondow()
{
	delete ui;
}

void LogInWondow::tact()
{
    if(task == 0)
    {
        interval = interval/1.0002;
        ui->progressBar->setValue(int(ui->progressBar->value() + interval));
    }
    if(task == 1)
    {
        timer->stop();
        emit loginedIn(apiKey_,secretKey_);
    }
    if(task == 2)
    {

        ui->progressBar->setHidden(1);
        ui->progressBar->setValue(0);
        timer->stop();
    }
}

void LogInWondow::on_pushButton_clicked()//Start
{
    task = 0;
	 ui->progressBar->setValue(startInterval);
	 interval = startInterval;
	 timer->start(1);
	 ui->progressBar->show();
     apiKey_ = ui->lineEditApiKey->text().toLatin1();
     secretKey_ = ui->lineEditSecretKey->text().toLatin1();
	 connect(logInKuna,&JKuna::gotMembers,this,&LogInWondow::gotMembers);
	 connect(logInKuna,&JKuna::errorGetMembers,this,&LogInWondow::errorGetMembers);
	 logInKuna->getMembers(ui->lineEditApiKey->text().toLatin1(),ui->lineEditSecretKey->text().toLatin1());
}

void LogInWondow::gotMembers(QList<JBalance> _wallet)
{
	ui->progressBar->setValue(ui->progressBar->maximum());
    timer->stop();
    task = 1;
    timer->start(500);
}

void LogInWondow::errorGetMembers()
{
	ui->progressBar->setValue(ui->progressBar->maximum());
    timer->stop();
    task = 2;
    timer->start(500);
    ui->labelInf->setText("Что-то пошло не так! Проверте ключи.");

}

void LogInWondow::on_pushButton_2_clicked()
{
    QApplication::closeAllWindows();
}
