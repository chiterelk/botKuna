#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "JKuna/jkuna.h"
#include "JKuna/jorderofdepth.h"
#include "JKuna/jbalance.h"
#include "loginwondow.h"
#include <QTimer>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();


private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonClose_clicked();

private:
	Ui::MainWindow *ui;
	JKuna *Kuna;
    LogInWondow * logIn;
    QString apiKey_;
    QString secretKey_;
    QTimer *timerGetTicker = new QTimer(this);

    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

        double perekritie = 0.3;//перекрытие в относительних единицах.
        int numberOrders = 4; //количество страховочних ордеров.
        //double otstup = 0.01;//отступ в относительних единицах.
        double martingeil = 0.01;//на сколько процентов увеличивается обьем следующего ордера.
        //double profit = 0.20;//Прибыль в относительных единицах, без учета комисии.
        double procent = 0.04;//Если цена выросла на это кол. процентов, то переставляем ордера.
        double depozit = 0.98;//процент от депозита.
        double Depozit = 100.00;//...
        double minSpread = 0.0;
        QString market;
        int process = 0; //1-Режим ожидания
                        //2-


    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    void getTicker(void);


	void gotTicker(JTicker _ticker);
	void gotDepth(QList <QList<JOrderOfDepth>> _depth);
	void gotTrades(QList <JOrderOfDepth> _trades);
	void gotMembers(QList <JBalance> _wallet);
	void gotOrders(QList <JActiveOrders> _activeOrders);
    void loginedIn(QString _apiKey, QString _secretKey);
};

#endif // MAINWINDOW_H
