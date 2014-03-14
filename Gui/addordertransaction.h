#ifndef ADDORDERTRANSACTION_H
#define ADDORDERTRANSACTION_H

#include "transaction.h"

#include <QDate>

namespace transactions {

class AddOrderTransaction : public Transaction
{
public:
	AddOrderTransaction(int nItemID, int nUserID, double fPriceOfEach, double fNumbers, QDate orderDate);
	virtual ~AddOrderTransaction();

	virtual bool Execute();

private:
	int _nItemID;
	int _nUserID;
	double _fPriceOfEach;
	double _fNumbers;
	QDate _orderDate;
};

}

#endif