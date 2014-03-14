#ifndef ADDUSERTRANSACTION_H
#define ADDUSERTRANSACTION_H

#include "transaction.h"

#include <string>

namespace transactions {

class AddUserTransaction : public Transaction
{
public:
	AddUserTransaction(const std::string &name);
	virtual ~AddUserTransaction();


	virtual bool Execute();

private:
	std::string _name;
};

}
#endif