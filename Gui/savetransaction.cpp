#include "savetransaction.h"
#include <fstream>
#include "menudatabase.h"

namespace transactions {

using namespace database;

bool transactions::SaveTransaction::Execute()
{
	std::ofstream outfile(_filename.c_str());
	if (!outfile.is_open()) {
		return false;
	}

	typedef std::vector<std::string> StringArray;
	StringArray users = g_mDatabase.GetUsers();
	outfile << users.size() << '\n';

	for (StringArray::iterator it = users.begin();
		it != users.end();
		++it )
	{
		outfile << g_mDatabase.GetUserID(*it) << '\t' << *it << '\n';
	}

	StringArray items = g_mDatabase.GetItems();
	outfile << items.size() << '\n';

	for (StringArray::iterator it = items.begin();
		it != items.end();
		++it)
	{
		outfile << g_mDatabase.GetItemID(*it) << '\t' << *it << '\n';
	}

	typedef database::MenuDatabase::OrderListType OrderArray;
	OrderArray orders = g_mDatabase.GetOrders();
	outfile << orders.size() << '\n';

	for (OrderArray::iterator it = orders.begin();
		it != orders.end();
		++it)
	{
		int y,m,d;
		

		outfile << (*it)->OrderID() << '\t'
			<< (*it)->UserID() << '\t' << (*it)->ItemID() << '\t'
			<< (*it)->PriceOfEach() << '\t' << (*it)->Numbers() << '\t';
		(*it)->OrderDate().getDate(&y, &m, &d);
		outfile << y << '\t' << m << '\t' << d << '\t';
		(*it)->InputDate().getDate(&y, &m, &d);
		outfile << y << '\t' << m << '\t' << d << '\n';
	}

	outfile.close();

	return true;	
}


SaveTransaction::SaveTransaction(std::string filename)
:_filename(filename)
{

}

SaveTransaction::~SaveTransaction()
{

}

}