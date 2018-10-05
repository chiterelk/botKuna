#include "jorderofdepth.h"

JOrderOfDepth::JOrderOfDepth(double _price, double _volume)
{
    price_ = _price;
    volume_ = _volume;
}

double JOrderOfDepth::getPrice()
{
    return price_;
}

double JOrderOfDepth::getVolume()
{
    return volume_;
}

QDateTime JOrderOfDepth::getTime()
{
    return createdAt_;
}

void JOrderOfDepth::setTime(QString _date)
{
    createdAt_ = QDateTime::fromString(_date,"yyyy-MM-ddTHH:mm:ssZ");
}
