#include "jorderofdepth.h"

JOrderOfDepth::JOrderOfDepth(double _price, double _volume)
{
    price_ = _price;
	 volume_ = _volume;
}

JOrderOfDepth::JOrderOfDepth(double _price, double _volume, QString _date)
{
	price_ = _price;
	volume_ = _volume;
	JOrderOfDepth::setTime(_date);
}

double JOrderOfDepth::getPrice()const
{
    return price_;
}

double JOrderOfDepth::getVolume()const
{
    return volume_;
}

QDateTime JOrderOfDepth::getTime()const
{
	return createdAt_;
}

QString JOrderOfDepth::getTimeString() const
{
	return createdAt_.toString("yyyy-MM-dd HH:mm:ss");
}

QString JOrderOfDepth::getTimeString(QString format) const
{
	return createdAt_.toString(format);
}

void JOrderOfDepth::setTime(QString _date)
{
    createdAt_ = QDateTime::fromString(_date,"yyyy-MM-ddTHH:mm:ssZ");
}
