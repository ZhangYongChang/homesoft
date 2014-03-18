#include "transaction.h"

namespace transactions {

std::string Transaction::GetLastError()
{
	return _error;
}

Transaction::~Transaction()
{
}

Transaction::Transaction()
{
}

}