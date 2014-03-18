#ifndef SAVETRANSACTION_H
#define SAVETRANSACTION_H

#include "transaction.h"

namespace transactions {

class SaveTransaction : public Transaction
{
public:
	SaveTransaction(std::string filename);
	virtual ~SaveTransaction();

	virtual bool Execute();

private:
	std::string _filename;
};

}

#endif
