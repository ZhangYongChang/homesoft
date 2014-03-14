#ifndef QUERYBYDATETRANSACTION_H_
#define QUERYBYDATETRANSACTION_H_

#include "querytransaction.h"

#include <QDate>

namespace transactions {

class QueryByDateTransaction : public QueryTransaction
{
public:
	QueryByDateTransaction(QDate orderdate);
	virtual ~QueryByDateTransaction();

	virtual void Query();

private:
	QDate _orderdate;
};

}
#endif