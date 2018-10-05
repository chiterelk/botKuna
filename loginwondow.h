#ifndef LOGINWONDOW_H
#define LOGINWONDOW_H

#include <QMainWindow>

namespace Ui {
class LogInWondow;
}

class LogInWondow : public QMainWindow
{
	Q_OBJECT

public:
	explicit LogInWondow(QWidget *parent = 0);
	~LogInWondow();

private:
	Ui::LogInWondow *ui;
};

#endif // LOGINWONDOW_H
