#include "addusertransaction.h"
#include "menudatabase.h"

namespace transactions {

using namespace database;

bool AddUserTransaction::Execute()
{
	int nId = g_mDatabase.SuggestUserId();
	return g_mDatabase.AddUser(nId, _name);
}

AddUserTransaction::AddUserTransaction( const std::string &name )
: _name(name)
{

}

AddUserTransaction::~AddUserTransaction()
{

}

}