#include "loginwondow.h"
#include "ui_loginwondow.h"

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
	interval = interval/1.0002;
	ui->progressBar->setValue(int(ui->progressBar->value() + interval));
}

void LogInWondow::on_pushButton_clicked()//Start
{
	 ui->progressBar->setValue(startInterval);
	 interval = startInterval;
	 timer->start(1);
	 ui->progressBar->show();
	 connect(logInKuna,&JKuna::gotMembers,this,&LogInWondow::gotMembers);
	 connect(logInKuna,&JKuna::errorGetMembers,this,&LogInWondow::errorGetMembers);
	 logInKuna->getMembers(ui->lineEditApiKey->text().toLatin1(),ui->lineEditSecretKey->text().toLatin1());
}

void LogInWondow::gotMembers(QList<JBalance> _wallet)
{
	ui->progressBar->setValue(ui->progressBar->maximum());
}

void LogInWondow::errorGetMembers()
{
	ui->progressBar->setValue(ui->progressBar->maximum());
	timer->stop();
	ui->progressBar->setHidden(1);
	ui->progressBar->setValue(0);

}
