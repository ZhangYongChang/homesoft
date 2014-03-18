#ifndef COUNRTBYMONTHANDUSERTRANSACTION_H
#define COUNRTBYMONTHANDUSERTRANSACTION_H

#include "countertransaction.h"

#include <QDate>

namespace transactions
{

    class CounterByMonthAndUserTransaction : public CounterTransaction
    {
    public:
        CounterByMonthAndUserTransaction(QDate date, std::string name);
        virtual ~CounterByMonthAndUserTransaction();

        virtual void Count();

    private:
        QDate _date;
        std::string _name;
    };

}
#endif