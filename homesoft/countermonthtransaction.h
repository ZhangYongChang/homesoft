#ifndef COUNTERBYMONTHANDUSERTRANSACTION_H
#define COUNTERBYMONTHANDUSERTRANSACTION_H

#include "countertransaction.h"

#include <QDate>

namespace transactions {

class CounterMonthTransaction : public CounterTransaction
{
public:
	CounterMonthTransaction(QDate date);
	virtual ~CounterMonthTransaction();

	virtual void Count();

private:
	QDate _date;
};

}
#endif