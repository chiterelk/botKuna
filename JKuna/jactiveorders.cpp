#include "jactiveorders.h"

JActiveOrders::JActiveOrders(int _id, QString _side, QString _ord_type,	double _price,	double _avg_price,
				  QString _state,	QString _market, QString _created_at, double _volume,
				  double _remaining_volume, double _executed_volume, int _trades_count) : JOrderOfDepth(_price,_volume,_created_at)
{
	id_ = _id;
	side_ = _side;
	ord_type_ = _ord_type;
	avg_price_ = _avg_price;
	state_ = _state;
	market_ = _market;
	remaining_volume_ = _remaining_volume;
	executed_volume_ = _executed_volume;
	trades_count_ = _trades_count;
}
