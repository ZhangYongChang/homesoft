#include "counterbymonthandusertransaction.h"
#include "querybynameanddatetransaction.h"
#include "order.h"

namespace transactions
{

    void CounterByMonthAndUserTransaction::Count()
    {
        _dfSum = 0.0;

        QueryTransaction *qt = new QueryByNameAndDateTransaction(_date, _name);
        qt->Execute();
        std::vector<Order *> orders = qt->GetRecord();
        for (std::vector<Order *>::iterator it = orders.begin();
             it != orders.end();
             ++it) {
            _dfSum = _dfSum + (*it)->PriceOfEach() * (*it)->Numbers();
        }

        delete qt;
    }

    CounterByMonthAndUserTransaction::CounterByMonthAndUserTransaction( QDate date, std::string name )
        : _date(date), _name(name)
    {

    }

    CounterByMonthAndUserTransaction::~CounterByMonthAndUserTransaction()
    {

    }

}