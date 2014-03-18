#ifndef ORDER_H
#define ORDER_H

#include <QDate>

class Order
{
public:
    Order();

    Order(int nItemID,
          int nUserID,
          double fPriceOfEach,
          double fNumbers,
          QDate date);

    static Order *CreateOrder(int nOrderID,
                              int nItemID,
                              int nUserID,
                              double fPriceOfEach,
                              double fNumbers,
                              QDate orderdate,
                              QDate inputdate);

    int OrderID() const;
    void OrderID(int val);
    int ItemID() const;
    void ItemID(int val);
    int UserID() const;
    void UserID(int val);
    double PriceOfEach() const;
    void PriceOfEach(double val);
    double Numbers() const;
    void Numbers(double val);
    QDate OrderDate() const;
    void OrderDate(QDate val);
    QDate InputDate() const;
    void InputDate(QDate val);

private:
    int _nOrderID;
    int _nItemID;
    int _nUserID;
    double _fPriceOfEach;
    double _fNumbers;
    QDate _orderDate;
    QDate _inputDate;

private:
    static int nMaxID;
};

#endif