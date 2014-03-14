#include "querybydatetransaction.h"
#include "menudatabase.h"

namespace transactions {

using namespace database;

void QueryByDateTransaction::Query()
{
	MenuDatabase::OrderListType orders =g_mDatabase.GetOrders();
	for (MenuDatabase::OrderListType::iterator it = orders.begin();
		it != orders.end();
		++it)
	{
		if ((*it)->OrderDate().month() == this->_orderdate.month())
		{
			result.push_back(*it);
		}
	}	
}

QueryByDateTransaction::QueryByDateTransaction( QDate orderdate )
{

}

QueryByDateTransaction::~QueryByDateTransaction()
{

}

}