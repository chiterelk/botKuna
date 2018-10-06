#ifndef LOGINWONDOW_H
#define LOGINWONDOW_H

#include <QMainWindow>
#include <QTimer>
#include <JKuna/jkuna.h>

namespace Ui {
class LogInWondow;
}

class LogInWondow : public QMainWindow
{
	Q_OBJECT

public:
	explicit LogInWondow(QWidget *parent = 0);
	~LogInWondow();
	void tact(void);

private slots:
	void on_pushButton_clicked();
	void gotMembers(QList <JBalance> _wallet);
	void errorGetMembers();

private:
	Ui::LogInWondow *ui;
	QTimer * timer;
	JKuna * logInKuna;
	int startInterval = 1000000000/5000;
	int interval = 0;
};


#endif // LOGINWONDOW_H
