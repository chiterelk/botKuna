#ifndef JORDEROFDEPTH_H
#define JORDEROFDEPTH_H

#include <QDateTime>

class JOrderOfDepth
{
public:
    JOrderOfDepth(double _price, double _volume);
    double getPrice(void);
    double getVolume(void);
    QDateTime getTime(void);
    void setTime(QString _date);
private:
    double price_ = 0.0;
    double volume_ = 0.0;
    QDateTime createdAt_;

};

#endif // JORDEROFDEPTH_H
