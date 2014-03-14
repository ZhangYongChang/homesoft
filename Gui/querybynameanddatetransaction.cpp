#include "querybynameanddatetransaction.h"
#include "menudatabase.h"

namespace transactions {

using namespace database;

void QueryByNameAndDateTransaction::Query()
{
	int nUserID = g_mDatabase.GetUserID(_name);
	MenuDatabase::OrderListType orders =g_mDatabase.GetOrders();
	for (MenuDatabase::OrderListType::iterator it = orders.begin();
		it != orders.end();
		++it)
	{
		if ((*it)->OrderDate() == this->_orderdate && (*it)->UserID() == nUserID)
		{
			result.push_back(*it);
		}
	}
}

QueryByNameAndDateTransaction::QueryByNameAndDateTransaction( QDate orderdate, const std::string &name )
:_orderdate(orderdate), _name(name)
{
}

QueryByNameAndDateTransaction::~QueryByNameAndDateTransaction()
{

}

}