#ifndef JKUNA_H
#define JKUNA_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include "JKuna/jticker.h"


class JKuna : public QObject
{
	Q_OBJECT
public:
	explicit JKuna(QObject *parent = nullptr);
	void getTicker(QString symbol);
	void getMembers(QString _apiKey, QString _secretKey);
	void getOrders(QString _apiKey, QString _secretKey, QString _market);


private:
	void gotReply_(QNetworkReply* reply);
	QNetworkAccessManager* NAM;
signals:
	void gotTicker(JTicker _ticker);
};

#endif // JKUNA_H
