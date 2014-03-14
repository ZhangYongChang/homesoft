#ifndef COUNTERTRANSACTION_H
#define COUNTERTRANSACTION_H

#include "transaction.h"

namespace transactions {

class CounterTransaction : public Transaction
{
public:
	CounterTransaction();
	virtual ~CounterTransaction();

	virtual void Count() = 0;

	double GetCount();

	virtual bool Execute();

protected:
	double _dfSum;
};

}
#endif