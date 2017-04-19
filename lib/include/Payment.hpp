#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include "Date.hpp"
class Bill;

class Payment
{
public:
    Payment( Bill* bill );
    virtual ~Payment() = default;

    bool isPaid();

    // getters & setters
    int getAmountPaid();
    void setAmountPaid( int val );
    Date getDatePaid();
    void setDatePaid( Date val );
    void setBillPtr( Bill* bill );
    Bill* getBillPtr();

protected:

private:
    int amountPaid;
    Date datePaid;
    Bill* bill;
};

#endif // PAYMENT_HPP
