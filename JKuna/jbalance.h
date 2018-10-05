#ifndef JBALANCE_H
#define JBALANCE_H

#include <QString>

class JBalance
{
public:
	JBalance(QString _currency, double _balance, double _locked);
	QString getCurrency()const;
	double getBalance()const;
	double getLocked()const;
private:
	QString currency_;
	double balance_ = 0.0;
	double locked_ = 0.0;
};

#endif // JBALANCE_H
