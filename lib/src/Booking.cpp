#include "Booking.hpp"
#include "Customer.hpp"

int Booking::autoID = 1;

Booking::Booking( int days, Room& room, Customer& customer, Date dateStart, bool state ) :
    ID( autoID ),
    days( days ),
    room( room ),
    customer( customer ),
    dateStart( dateStart ),
    dateEnd( dateStart + ( days - 1 ) ),
    state( state ),
    bill( Bill( this ) )
{

    ++autoID;
}

int Booking::getID()
{
    return ID;
}

int Booking::getDays()
{
    return days;
}

void Booking::setDays( int val )
{
    days = val;
}

Room& Booking::getRoom()
{
    return room;
}

void Booking::setRoom( Room& val )
{
    room = val;
}

Customer& Booking::getCustomer()
{
    return customer;
}

void Booking::setCustomer( Customer& val )
{
    customer = val;
}

Date Booking::getDateStart()
{
    return dateStart;
}

void Booking::setDateStart( Date val )
{
    dateStart = val;
}

Date Booking::getDateEnd()
{
    return dateEnd;
}

void Booking::setDateEnd( Date val )
{
    dateEnd = val;
}

bool Booking::getState()
{
    return state;
}

void Booking::setState( bool val )
{
    state = val;
}

Bill& Booking::getBill()
{
    return bill;
}
