#include "loginwondow.h"
#include "ui_loginwondow.h"

LogInWondow::LogInWondow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::LogInWondow)
{
	ui->setupUi(this);
}

LogInWondow::~LogInWondow()
{
	delete ui;
}
