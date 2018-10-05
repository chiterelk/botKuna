#ifndef JORDEROFDEPTH_H
#define JORDEROFDEPTH_H

#include <QDateTime>

class JOrderOfDepth
{
public:
	JOrderOfDepth(double _price, double _volume);
	JOrderOfDepth(double _price, double _volume, QString _date);
	double getPrice(void)const;
	double getVolume(void)const;
	QDateTime getTime(void)const;
	QString getTimeString()const;
	QString getTimeString(QString format)const;
	void setTime(QString _date);
private:
	double price_ = 0.0;
	double volume_ = 0.0;
	QDateTime createdAt_;

};

#endif // JORDEROFDEPTH_H
