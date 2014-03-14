#include "querytransaction.h"

namespace transactions {

bool QueryTransaction::Execute()
{
	Query();

	return true;
}

std::vector<Order *> QueryTransaction::GetRecord()
{
	return result;
}

QueryTransaction::QueryTransaction()
{

}

QueryTransaction::~QueryTransaction()
{

}

}