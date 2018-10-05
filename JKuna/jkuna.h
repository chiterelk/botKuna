#ifndef JKUNA_H
#define JKUNA_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include "JKuna/jticker.h"
#include "JKuna/jorderofdepth.h"


class JKuna : public QObject
{
	Q_OBJECT
public:
	explicit JKuna(QObject *parent = nullptr);
    void getTicker(QString _symbol);
    void getDepth(QString _symbol);
    void getTrades(QString _symbol);
	void getMembers(QString _apiKey, QString _secretKey);
    void getOrders(QString _apiKey, QString _secretKey, QString _market);
    void openSellOrders(QString _apiKey, QString _secretKey, QString _market, double _volume, double _price);
    void openBuyOrders(QString _apiKey, QString _secretKey, QString _market, double _volume, double _price);
    void deleteOrder(QString _apiKey, QString _secretKey,QString _id);

private:
	void gotReply_(QNetworkReply* reply);
	QNetworkAccessManager* NAM;
signals:
	void gotTicker(JTicker _ticker);
    void gotDepth(QList <QList<JOrderOfDepth>> _depth);
};

#endif // JKUNA_H
