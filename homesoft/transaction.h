#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

namespace transactions {

class Transaction
{
public:
	Transaction();

	virtual ~Transaction();

	virtual bool Execute() = 0;

	std::string GetLastError();

protected:
	std::string _error;
};

}

#endif