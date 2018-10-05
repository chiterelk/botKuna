#ifndef JKUNA_H
#define JKUNA_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include "JKuna/jticker.h"
#include "JKuna/jorderofdepth.h"
#include "JKuna/jbalance.h"
#include "JKuna/jactiveorders.h"


class JKuna : public QObject
{
	Q_OBJECT
public:
	explicit JKuna(QObject *parent = nullptr);
	void getTicker(QString _symbol); //Получение котировок
	void getDepth(QString _symbol);	//Получение биржевого стакана
	void getTrades(QString _symbol);	//История сделок
	void getMembers(QString _apiKey, QString _secretKey);//Информация об акаунте и балансы
	void getOrders(QString _apiKey, QString _secretKey, QString _market);//Информация об выставленных ордерах
	void openSellOrders(QString _apiKey, QString _secretKey, QString _market, double _volume, double _price);//Выставить ордер на продажу
	void openBuyOrders(QString _apiKey, QString _secretKey, QString _market, double _volume, double _price);//Выставить ордер на покупку
	void deleteOrder(QString _apiKey, QString _secretKey,QString _id);

private:
	void gotReply_(QNetworkReply* reply);
	QNetworkAccessManager* NAM;
signals:
	void gotTicker(JTicker _ticker);
	void gotDepth(QList <QList<JOrderOfDepth>> _depth);
	void gotTrades(QList <JOrderOfDepth> _trades);
	void gotMembers(QList <JBalance> _wallet);
	void gotOrders(QList <JActiveOrders> _activeOrders);
	void orderIsOpened(JActiveOrders _openedOrder);
	void orderIsDeleted(JActiveOrders _deletedOrder);
};

#endif // JKUNA_H
