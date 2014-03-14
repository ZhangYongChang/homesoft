#include "loadtransaction.h"

#include <fstream>

#include "menudatabase.h"

namespace transactions {
using namespace database;

LoadTransaction::LoadTransaction( std::string filename )
: _filename(filename)
{

}

LoadTransaction::~LoadTransaction()
{
}

bool transactions::LoadTransaction::Execute()
{
	std::ifstream infile(_filename.c_str());
	if (!infile.is_open()) {
		return false;
	}

	int NumberOfUsers = 0;
	infile >> NumberOfUsers;
	std::string username;
	int userid = 0;

	for (int nCount = 0 ; nCount < NumberOfUsers; ++nCount)
	{
		infile >> userid >> username;
		g_mDatabase.AddUser(userid, username);
	}

	int NumberOfItems = 0;
	infile >> NumberOfItems;
	std::string itemname;
	int itemid = 0;

	for (int nCount = 0 ; nCount < NumberOfItems; ++nCount)
	{
		infile >> itemid >> itemname;
		g_mDatabase.AddItemInfo(itemid, itemname);
	}

	int NumberOfOrders = 0;
	infile >> NumberOfOrders;

	int nOrderID;
	int nItemID;
	int nUserID;
	double fPriceOfEach;
	double fNumbers;
	QDate orderDate;
	QDate inputDate;

	int y,m,d;
	for (int nCount = 0 ; nCount < NumberOfOrders; ++nCount)
	{
		infile >> nOrderID >> nUserID >> nItemID >> fPriceOfEach >> fNumbers;
		infile >> y >> m >> d;
		orderDate.setDate(y,m,d);
		infile >> y >> m >> d;
		inputDate.setDate(y,m,d);

		Order *order = Order::CreateOrder(nOrderID,nItemID,nUserID, fPriceOfEach, fNumbers, orderDate, inputDate);
		g_mDatabase.AddOrder(order);
	}
	
	return true;
}

}