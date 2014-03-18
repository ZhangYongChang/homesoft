#include "addordertransaction.h"
#include "order.h"
#include "menudatabase.h"

namespace transactions {

using namespace database;

bool AddOrderTransaction::Execute()
{
	Order *order = new Order(_nItemID, _nUserID, _fPriceOfEach, _fNumbers, _orderDate);
	g_mDatabase.AddOrder(order);

	return true;
}

AddOrderTransaction::AddOrderTransaction( int nItemID, int nUserID, double fPriceOfEach, double fNumbers, QDate orderDate )
:_nItemID(nItemID), _nUserID(nUserID), _fPriceOfEach(fPriceOfEach), _fNumbers(fNumbers), _orderDate(orderDate)
{

}

AddOrderTransaction::~AddOrderTransaction()
{

}

}