#include "countertransaction.h"

namespace transactions {

double CounterTransaction::GetCount()
{
	return _dfSum;
}

bool CounterTransaction::Execute()
{
	Count();
	return true;
}

CounterTransaction::CounterTransaction()
{
	_dfSum = 0;
}

CounterTransaction::~CounterTransaction()
{

}

}