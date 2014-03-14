#include "additemstyletransaction.h"
#include "menudatabase.h"

namespace transactions {

using namespace database;

bool AddItemClassificationTransaction::Execute()
{
    int nId = g_mDatabase.SuggestItemId();
    return g_mDatabase.AddItemInfo(nId, _name);
}

AddItemClassificationTransaction::AddItemClassificationTransaction( const std::string &name )
    : _name(name)
{

}

AddItemClassificationTransaction::~AddItemClassificationTransaction()
{

}

}