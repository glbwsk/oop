#include "Receptionist.hpp"

Receptionist::Receptionist( Employee employee ) :
    Employee( employee )
{

}

void Receptionist::confirmBooking( Booking& booking )
{
    booking.setState( true );
}

void Receptionist::bookUnconfirmed( std::list<Booking> &uBookingsVec, std::list<Booking> &bookingsVec )
{

    for( auto it : uBookingsVec )
    {
        if ( checkIfDateAvailable( it.getDays(), it.getRoom(), it.getDateStart(), bookingsVec ) )
        {
            bookingsVec.push_back( it );
            bookingsVec.back().getBill().setBookingPtr( &bookingsVec.back() );
            bookingsVec.back().getBill().getPayment().setBillPtr( &bookingsVec.back().getBill() );
            it.getCustomer().getBookings().push_back( &bookingsVec.back() );
            confirmBooking( bookingsVec.back() );
        }
    }

    uBookingsVec.clear();
}

void Receptionist::addCustomer( Person person, std::list<Customer> &cusVec )
{
    Person newPerson( person );
    cusVec.push_back( newPerson );
}

bool Receptionist::checkIfDateAvailable( int days, Room& room, Date dateStart, std::list<Booking> &bookingsVec )
{
    bool value = true;
    for ( auto i : bookingsVec )
    {
        if ( &room == &i.getRoom() )
        {
            if ( dateStart < i.getDateStart() )
            {
                if ( ( dateStart + ( days - 1 ) ) < i.getDateStart() )
                {
                    continue;
                }
                else
                {
                    if ( i.getState() == true )
                    {
                        value = false;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                if ( dateStart > i.getDateEnd() )
                {
                    continue;
                }
                else
                {
                    if ( i.getState() == true )
                    {
                        value = false;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        else
        {
            continue;
        }
    }

    return value;
}

void Receptionist::removeEquipment ( Room& room, int index )
{
    room.getEquipment().erase ( room.getEquipment().begin() + index );
}
