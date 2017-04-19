#include "Customer.hpp"

Customer::Customer( Person person ) :
    Person ( person )
{

}

void Customer::book( int days, Room& room, Date dateStart, std::list<Booking>& uBookingsVec )
{
    Booking newBooking = Booking( days, room, *this, dateStart, false );

    uBookingsVec.push_back( newBooking );
    uBookingsVec.back().getBill().setBookingPtr( &uBookingsVec.back() );
    uBookingsVec.back().getBill().getPayment().setBillPtr( &uBookingsVec.back().getBill() );
}

bool Customer::pay( Booking& booking, int amount )
{
    if ( booking.getState() == true && &booking.getCustomer() == this && booking.getBill().getPayment().isPaid() == false )
    {
        booking.getBill().getPayment().setAmountPaid( amount );
        booking.getBill().getPayment().setDatePaid( Date() );
        return true;
    }

    return false;
}

std::vector<Booking*>& Customer::getBookings()
{
    return bookings;
}
