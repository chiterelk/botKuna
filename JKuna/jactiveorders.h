#ifndef JACTIVEORDERS_H
#define JACTIVEORDERS_H


#include "jorderofdepth.h"
#include <QString>
#include <QDateTime>

class JActiveOrders: public JOrderOfDepth
{
public:
	JActiveOrders(int _id, QString _side, QString _ord_type,	double _price,	double _avg_price,
					  QString _state,	QString _market, QString _created_at, double _volume,
					  double _remaining_volume, double _executed_volume, int _trades_count);

	int getId()const{return id_;};
	QString getSide()const{return side_;};
	QString getOrd_type()const{return ord_type_;};
	double getAvg_price()const{return avg_price_;};
	QString getState()const{return state_;};
	QString getMarket()const{return market_;};
	double getRemaining_volume()const{return remaining_volume_;};
	double getExecuted_volume()const{return executed_volume_;};
	int getTrades_count()const{return trades_count_;};

private:
	int id_ = 0;
	QString side_;
	QString ord_type_;
	//double price_ = 0.0;
	double avg_price_ = 0.0;
	QString state_;
	QString market_;
	//QDateTime created_at_;
	//double volume_ = 0.0;
	double remaining_volume_ = 0.0;
	double executed_volume_ = 0.0;
	int trades_count_ = 0;
};

#endif // JACTIVEORDERS_H
