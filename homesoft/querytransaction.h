#ifndef QUERYTRANSACTION_H
#define QUERYTRANSACTION_H

#include "transaction.h"

#include <vector>

class Order;

namespace transactions {

class QueryTransaction : public Transaction
{
public:
	QueryTransaction();
	virtual ~QueryTransaction();
	virtual bool Execute();
	virtual std::vector<Order *> GetRecord();

protected:
	virtual void Query() = 0;	

protected:
	std::vector<Order *> result;
};

}
#endif