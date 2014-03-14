#ifndef MMDATABASE_H_
#define MMDATABASE_H_

#include "order.h"

#include <map>
#include <vector>

#include <string>

namespace database {

class MenuDatabase
{
public:
	typedef std::vector<Order *> OrderListType;

public:
	MenuDatabase();
	virtual ~MenuDatabase();

	// Users Management
	int GetUserID(const std::string &name);
	bool AddUser(const int &id, const std::string &name);
	int SuggestUserId();
	std::vector<std::string> GetUsers();
	std::string GetUserName(const int &id);

	// Items Management
	int GetItemID(const std::string &name);
	bool AddItemInfo(const int &id, const std::string &name);
	int SuggestItemId();
	std::vector<std::string> GetItems();
	std::string GetItemName(const int &id);

	// Order Management
	void AddOrder(Order *order);
	void DeleteOrder(int nOrderID);
	OrderListType GetOrders();

	// Error Management
	std::string GetLastError();

private:
	typedef std::map<std::string, int> UserTableType;
	typedef std::map<std::string, int> ItemTableType;
	
	UserTableType users;
	ItemTableType items;
	OrderListType orders;

	std::string _error;
};

extern MenuDatabase g_mDatabase;

}

#endif