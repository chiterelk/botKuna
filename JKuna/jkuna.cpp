#include "jkuna.h"
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QDateTime>
#include <QMessageAuthenticationCode>
#include <QCryptographicHash>
#include "JKuna/jorderofdepth.h"


JKuna::JKuna(QObject *parent) : QObject(parent)
{
	NAM = new QNetworkAccessManager(this);
    connect(NAM,&QNetworkAccessManager::finished,this,&JKuna::gotReply_);
}

void JKuna::getTicker(QString _symbol)
{
    NAM->get(QNetworkRequest(QUrl("https://kuna.io/api/v2/tickers/" + _symbol)));
}

void JKuna::getDepth(QString _symbol)
{
    NAM->get(QNetworkRequest(QUrl("https://kuna.io/api/v2/depth?market=" + _symbol)));
}

void JKuna::getTrades(QString _symbol)
{
    NAM->get(QNetworkRequest(QUrl("https://kuna.io/api/v2/trades?market=" + _symbol)));
}

void JKuna::getMembers(QString _apiKey, QString _secretKey)
{
	QString tonce = QString::number(QDateTime::currentDateTime().toTime_t());
	QByteArray HTTP_verb = "GET";
	QByteArray URI = "/api/v2/members/me";
	QByteArray URL = "https://kuna.io/api/v2/members/me";
	QByteArray params = "access_key="+ _apiKey.toUtf8() + "&tonce=" + tonce.toUtf8()+"000";

	QMessageAuthenticationCode code(QCryptographicHash::Sha256);
	code.setKey(_secretKey.toUtf8());
	code.addData(HTTP_verb+"|"+URI+"|"+params);
	QByteArray signature = code.result().toHex();

    NAM->get(QNetworkRequest(QUrl(QString(URL)+"?"+QString(params)+"&signature="+QString(signature))));
}

void JKuna::getOrders(QString _apiKey, QString _secretKey, QString _market)
{
	QString tonce = QString::number(QDateTime::currentDateTime().toTime_t());
	QByteArray HTTP_verb = "GET";
	QByteArray URI = "/api/v2/orders";
	QByteArray URL = "https://kuna.io/api/v2/orders";
	QByteArray params = "access_key="+ _apiKey.toUtf8() + "&market=" + _market.toUtf8() + "&tonce=" + tonce.toUtf8()+"000";

	QMessageAuthenticationCode code(QCryptographicHash::Sha256);
	code.setKey(_secretKey.toUtf8());
	code.addData(HTTP_verb+"|"+URI+"|"+params);
	QByteArray signature = code.result().toHex();

    NAM->get(QNetworkRequest(QUrl(QString(URL)+"?"+QString(params)+"&signature="+QString(signature))));
}

void JKuna::openSellOrders(QString _apiKey, QString _secretKey, QString _market, double _volume, double _price)
{
    QString tonce = QString::number(QDateTime::currentDateTime().toTime_t());
    QByteArray HTTP_verb = "POST";
    QByteArray URI = "/api/v2/orders";
    QByteArray URL = "https://kuna.io/api/v2/orders";
    QByteArray params = "access_key="+ _apiKey.toUtf8() + "&market=" + _market.toUtf8() +"&price=" + QString::number(_price).toUtf8() +
            "&side=sell"+ "&tonce=" + tonce.toUtf8()+"000" + "&volume=" + QString::number(_volume).toUtf8();

    QMessageAuthenticationCode code(QCryptographicHash::Sha256);
    code.setKey(_secretKey.toUtf8());
    code.addData(HTTP_verb+"|"+URI+"|"+params);
    QByteArray signature = code.result().toHex();


    QNetworkRequest request;

    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    //request.setRawHeader("Api-Key",_apiKey.toUtf8());
    //request.setRawHeader("signature",signature);
    request.setUrl(QUrl(QString(URL)));
    NAM->post(request,params+"&signature="+signature);
}

void JKuna::openBuyOrders(QString _apiKey, QString _secretKey, QString _market, double _volume, double _price)
{
    QString tonce = QString::number(QDateTime::currentDateTime().toTime_t());
    QByteArray HTTP_verb = "POST";
    QByteArray URI = "/api/v2/orders";
    QByteArray URL = "https://kuna.io/api/v2/orders";
    QByteArray params = "access_key="+ _apiKey.toUtf8() + "&market=" + _market.toUtf8() +"&price=" + QString::number(_price).toUtf8() +
            "&side=buy"+ "&tonce=" + tonce.toUtf8()+"000" + "&volume=" + QString::number(_volume).toUtf8();

    QMessageAuthenticationCode code(QCryptographicHash::Sha256);
    code.setKey(_secretKey.toUtf8());
    code.addData(HTTP_verb+"|"+URI+"|"+params);
    QByteArray signature = code.result().toHex();


    QNetworkRequest request;

    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    request.setUrl(QUrl(QString(URL)));
    NAM->post(request,params+"&signature="+signature);
}

void JKuna::deleteOrder(QString _apiKey, QString _secretKey,QString _id)
{
    QString tonce = QString::number(QDateTime::currentDateTime().toTime_t());
    QByteArray HTTP_verb = "POST";
    QByteArray URI = "/api/v2/order/delete";
    QByteArray URL = "https://kuna.io/api/v2/order/delete";
    QByteArray params = "access_key="+ _apiKey.toUtf8() + "&id=" + _id.toUtf8() + "&tonce=" + tonce.toUtf8()+"000";

    QMessageAuthenticationCode code(QCryptographicHash::Sha256);
    code.setKey(_secretKey.toUtf8());
    code.addData(HTTP_verb+"|"+URI+"|"+params);
    QByteArray signature = code.result().toHex();


    QNetworkRequest request;

    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    request.setUrl(QUrl(QString(URL)));
    NAM->post(request,params+"&signature="+signature);
}



void JKuna::gotReply_(QNetworkReply *reply)
{
	QString url = reply->url().toString();
    qDebug()<< url;
	if(!reply->error())
	{
		QByteArray document = reply->readAll();
		qDebug()<<document;

		if(url.indexOf("/api/v2/tickers")>=0)
		{
			QJsonDocument doc = QJsonDocument::fromJson(document);
			QJsonObject obj = doc.object();
			QJsonObject objTicker = obj.value("ticker").toObject();
			JTicker ticker = JTicker(objTicker.value("buy").toString().toDouble(),
											 objTicker.value("sell").toString().toDouble(),
											 objTicker.value("low").toString().toDouble(),
											 objTicker.value("high").toString().toDouble(),
											 objTicker.value("last").toString().toDouble(),
											 objTicker.value("vol").toString().toDouble(),
											 objTicker.value("amoun").toString().toDouble());
			emit gotTicker(ticker);//сигнал о получении тикеров
		}
        if(url.indexOf("/api/v2/depth")>=0)
        {
            QJsonDocument doc = QJsonDocument::fromJson(document);
            QJsonObject obj = doc.object();
            QJsonArray asks = obj.value("asks").toArray();
            QList <JOrderOfDepth> ask;
            if(asks.count()>0)
            {
                for(int i = 0; i<asks.count();i++)
                {
                    ask << JOrderOfDepth(asks.at(i).toArray().at(0).toString().toDouble(),asks.at(i).toArray().at(1).toString().toDouble());
                }
            }
            QJsonArray bids = obj.value("bids").toArray();
            QList <JOrderOfDepth> bid;
            if(bids.count()>0)
            {
                for(int i = 0; i<bids.count();i++)
                {
                    bid << JOrderOfDepth(bids.at(i).toArray().at(0).toString().toDouble(),bids.at(i).toArray().at(1).toString().toDouble());
                }
            }
            QList <QList<JOrderOfDepth>> depth;
            depth << ask;
            depth << bid;
            emit gotDepth(depth);
            ask.clear();
            bid.clear();
            depth.clear();
        }
        if(url.indexOf("/api/v2/trades?market=")>=0)
		{
            QJsonDocument doc = QJsonDocument::fromJson(document);
            QJsonArray arr = doc.array();
            QList <JOrderOfDepth> trades;
            if(arr.count()>0)
            {
                for(int i = 0; i<arr.count();i++)
                {
                    trades << JOrderOfDepth(arr.at(i).toObject().value("price").toString().toDouble(),arr.at(i).toObject().value("volume").toString().toDouble());
                    trades.last().setTime(arr.at(i).toObject().value("created_at").toString());
                }
            }
            qDebug()<<trades.count();
		}
	}else{
		qDebug()<<reply->errorString();
        qDebug()<<reply->error();
	}
}
