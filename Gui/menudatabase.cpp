#include "menudatabase.h"

namespace database {

MenuDatabase g_mDatabase;

MenuDatabase::MenuDatabase()
{

}

MenuDatabase::~MenuDatabase()
{

}

int MenuDatabase::GetUserID( const std::string &name )
{
	UserTableType::iterator it = users.find(name);
	if (it != users.end())
	{
		return it->second;
	} 
	else
	{
		return -1;
	}
}

std::string MenuDatabase::GetLastError()
{
	return _error;
}

bool MenuDatabase::AddUser( const int &id, const std::string &name )
{
	UserTableType::iterator it = users.find(name);
	if (it == users.end())
	{
		users[name] = id;
		return true;
	}

	return false;
}

int MenuDatabase::SuggestUserId()
{
	int max = 0;
	for (UserTableType::iterator it = users.begin();
		it != users.end();
		++it)
	{
		if (max < it->second)
		{
			max = it->second;
		}
	}

	return max;
}

int MenuDatabase::GetItemID( const std::string &name )
{

	ItemTableType::iterator it = items.find(name);
	if (it != items.end())
	{
		return it->second;
	} 
	else
	{
		return -1;
	}

}

bool MenuDatabase::AddItemInfo( const int &id, const std::string &name )
{
	ItemTableType::iterator it = items.find(name);
	if (it == items.end())
	{
		items[name] = id;
		return true;
	}

	return false;
}

int MenuDatabase::SuggestItemId()
{
	int max = 0;
	for (ItemTableType::iterator it = items.begin();
		it != items.end();
		++it)
	{
		if (max < it->second)
		{
			max = it->second;
		}
	}

	return max;
}

std::vector<std::string> MenuDatabase::GetUsers()
{
	std::vector<std::string> v;
	for (UserTableType::iterator it = users.begin();
		it != users.end();
		++it)
	{
		v.push_back(it->first);
	}

	return v;
}

std::vector<std::string> MenuDatabase::GetItems()
{
	std::vector<std::string> v;
	for (ItemTableType::iterator it = items.begin();
		it != items.end();
		++it)
	{
		v.push_back(it->first);
	}

	return v;
}

void MenuDatabase::AddOrder( Order *order )
{
	orders.push_back(order);
}

void MenuDatabase::DeleteOrder( int nOrderID )
{

}

MenuDatabase::OrderListType MenuDatabase::GetOrders()
{
	return orders;
}

std::string MenuDatabase::GetUserName( const int &id )
{
	for (UserTableType::iterator it = users.begin();
		it != users.end();
		++it)
	{
		if (it->second == id)
		{
			return it->first;
		}
	}

	return std::string();
}

std::string MenuDatabase::GetItemName( const int &id )
{
	for (ItemTableType::iterator it = items.begin();
		it != items.end();
		++it)
	{
		if (it->second == id)
		{
			return it->first;
		}
	}

	return std::string();
}

}