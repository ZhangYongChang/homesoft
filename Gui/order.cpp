#include "order.h"

Order::Order( int nItemID, int nUserID, double fPriceOfEach, double fNumbers, QDate date )
: _nItemID(nItemID), _nUserID(nUserID), _fPriceOfEach(fPriceOfEach), _fNumbers(fNumbers),
_orderDate(date)
{
	_inputDate = QDate::currentDate();
	_nOrderID = ++nMaxID;
}

Order::Order()
{

}

int Order::OrderID() const
{
	return _nOrderID;
}

void Order::OrderID( int val )
{
	_nOrderID = val;
}

int Order::ItemID() const
{
	return _nItemID;
}

void Order::ItemID( int val )
{
	_nItemID = val;
}

int Order::UserID() const
{
	return _nUserID;
}

void Order::UserID( int val )
{
	_nUserID = val;
}

double Order::PriceOfEach() const
{
	return _fPriceOfEach;
}

void Order::PriceOfEach( double val )
{
	_fPriceOfEach = val;
}

double Order::Numbers() const
{
	return _fNumbers;
}

void Order::Numbers( double val )
{
	_fNumbers = val;
}

QDate Order::OrderDate() const
{
	return _orderDate;
}

void Order::OrderDate( QDate val )
{
	_orderDate = val;
}

QDate Order::InputDate() const
{
	return _inputDate;
}

void Order::InputDate( QDate val )
{
	_inputDate = val;
}

Order * Order::CreateOrder( int nOrderID,int nItemID, int nUserID, double fPriceOfEach, double fNumbers, QDate orderdate, QDate inputdate )
{
	Order *order = new Order();
	order->OrderID(nOrderID);
	order->ItemID(nItemID);
	order->UserID(nUserID);
	order->PriceOfEach(fPriceOfEach);
	order->Numbers(fNumbers);
	order->OrderDate(orderdate);
	order->InputDate(inputdate);
	return order;
}

int Order::nMaxID = 0;
