#ifndef LOADTRANSACTION_H
#define LOADTRANSACTION_H

#include "transaction.h"

namespace transactions {

class LoadTransaction :	public Transaction
{
public:
	LoadTransaction(std::string filename);

	virtual ~LoadTransaction();

	virtual bool Execute();

private:
	std::string _filename;
};

}
#endif
