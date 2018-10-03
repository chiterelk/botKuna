#include "jticker.h"

JTicker::JTicker(double _buy, double _sell, double _low, double _high, double _last, double _vol, double _amoun)
{
	buy_ = _buy;
	sell_ = _sell;
	low_ = _low;
	high_ = _high;
	last_ = _last;
	vol_ = _vol;
	amoun_ = _amoun;
	spread_ = (_sell-_buy)/_sell;
}
