#include "Bill.hpp"
#include "Booking.hpp"

Bill::Bill( Booking* booking ) :
    amount ( booking->getDays() * booking->getRoom().getPricePerDay() ),
    payment( Payment( this ) ),
    booking( nullptr )
{

}

int Bill::getAmount()
{
    return amount;
}

void Bill::setAmount()
{
    this->amount = booking->getDays() * booking->getRoom().getPricePerDay();
}

Payment& Bill::getPayment()
{
    return payment;
}

void Bill::setBookingPtr( Booking* booking )
{
    this->booking = booking;
}

Booking* Bill::getBookingPtr()
{
    return booking;
}
