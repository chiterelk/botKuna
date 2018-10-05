#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "JKuna/jkuna.h"
#include "JKuna/jorderofdepth.h"
#include "JKuna/jbalance.h"
#include "loginwondow.h"

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
	LogInWondow * logIn;
	void gotTicker(JTicker _ticker);
	void gotDepth(QList <QList<JOrderOfDepth>> _depth);
	void gotTrades(QList <JOrderOfDepth> _trades);
	void gotMembers(QList <JBalance> _wallet);
	void gotOrders(QList <JActiveOrders> _activeOrders);
};

#endif // MAINWINDOW_H
