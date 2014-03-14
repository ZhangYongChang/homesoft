#include "countermonthtransaction.h"
#include "querybydatetransaction.h"
#include "order.h"

namespace transactions
{

    void CounterMonthTransaction::Count()
    {
        _dfSum = 0.0;

        QueryTransaction *qt = new QueryByDateTransaction(_date);
        qt->Execute();
        std::vector<Order *> orders = qt->GetRecord();
        for (std::vector<Order *>::iterator it = orders.begin();
             it != orders.end();
             ++it) {
            _dfSum = (*it)->PriceOfEach() * (*it)->Numbers();
        }

        delete qt;
    }

    CounterMonthTransaction::CounterMonthTransaction( QDate date )
        : _date(date)
    {

    }

    CounterMonthTransaction::~CounterMonthTransaction()
    {

    }

}
