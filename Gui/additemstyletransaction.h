#ifndef ADDITEMSTYLETRANSACTION_H
#define ADDITEMSTYLETRANSACTION_H

#include "transaction.h"

namespace transactions {

class AddItemClassificationTransaction : public Transaction
{
public:
	AddItemClassificationTransaction(const std::string &name);
	virtual ~AddItemClassificationTransaction();

	virtual bool Execute();

private:
	std::string _name;
};

}

#endif