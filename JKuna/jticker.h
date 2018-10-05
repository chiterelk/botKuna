 #ifndef JTICKER_H
#define JTICKER_H


class JTicker
{
public:
	JTicker(double _buy, double _sell, double _low,	double _high, double _last, double _vol, double _amoun);
	double getBuy()const{	return buy_;	}; //Bid
	double getSell()const{	return sell_;	}; //Ask
	double getLow()const{	return low_;	};
	double getHigh()const{	return high_;	};
	double getLast()const{	return last_;	};
	double getVol()const{	return vol_;	};
	double getAmoun()const{	return amoun_;	};
	double getSpread()const{	return spread_;	};
private:
	double buy_ = 0.0; //цена биткоина на покупку,
	double sell_ = 0.0; //цена биткоина на продажу,
	double low_ = 0.0; //наименьшая цена сделки за 24 часа,
	double high_ = 0.0; //наибольшая цена сделки за 24 часа,
	double last_ = 0.0; //цена последней сделки,
	double vol_ = 0.0; //объём торгов в базовой валюте за 24 часа,
	double amoun_ = 0.0;//общая стоимость торгов в котируемое валюте за 24 часа
	double spread_ = 0.0; //спред
};

#endif // JTICKER_H
