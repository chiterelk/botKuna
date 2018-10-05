#include "jbalance.h"

JBalance::JBalance(QString _currency, double _balance, double _locked)
{
	currency_ = _currency;
	balance_ = _balance;
	locked_ = _locked;
}

QString JBalance::getCurrency() const
{
	return currency_;
}

double JBalance::getBalance() const
{
	return balance_;
}

double JBalance::getLocked() const
{
	return locked_;
}


