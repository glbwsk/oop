#include "Payment.hpp"
#include "Bill.hpp"

Payment::Payment( Bill* bill ) :
    amountPaid ( 0 ),
    datePaid ( Date( 0, 0, 0 ) ),
    bill ( nullptr )
{

}

bool Payment::isPaid()
{
    if ( this->amountPaid >= this->bill->getAmount() )
        return true;
    else
        return false;
}

int Payment::getAmountPaid()
{
    return amountPaid;
}

void Payment::setAmountPaid( int val )
{
    amountPaid = val;
}

Date Payment::getDatePaid()
{
    return datePaid;
}

void Payment::setDatePaid( Date val )
{
    datePaid = val;
}

void Payment::setBillPtr( Bill* bill )
{
    this->bill = bill;
}

Bill* Payment::getBillPtr()
{
    return bill;
}
