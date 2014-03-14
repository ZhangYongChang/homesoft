#ifndef QUERYBYNAMEANDDATETRANSACTION_H
#define QUERYBYNAMEANDDATETRANSACTION_H

#include "querytransaction.h"
#include <QDate>

namespace transactions {

class QueryByNameAndDateTransaction : public QueryTransaction
{
public:
	QueryByNameAndDateTransaction(QDate orderdate, const std::string &name);
	virtual ~QueryByNameAndDateTransaction();

	virtual void Query();

private:
	QDate _orderdate;
	std::string _name;
};

}
#endif