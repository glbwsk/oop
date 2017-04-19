#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include "Person.hpp"
#include "Date.hpp"
#include "Booking.hpp"
#include "Room.hpp"

#include <vector>
#include <list>

class Customer : public Person
{
public:
    Customer( Person person = Person() );
    virtual ~Customer() = default;

    void book( int days, Room& room, Date dateStart, std::list<Booking>& uBookingsVec );
    bool pay( Booking& booking, int amount );

    // getters & setters
    std::vector<Booking*>& getBookings();

protected:

private:
    std::vector<Booking*> bookings;
};

#endif // CUSTOMER_HPP
