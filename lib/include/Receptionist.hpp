#ifndef RECEPTIONIST_HPP
#define RECEPTIONIST_HPP

#include "Employee.hpp"
#include "Booking.hpp"
#include "Room.hpp"
#include "Date.hpp"
#include "Customer.hpp"

#include <vector>
#include <list>

class Receptionist : public Employee
{
public:
    Receptionist( Employee employee );
    virtual ~Receptionist() = default;

    void confirmBooking( Booking& booking );
    void bookUnconfirmed( std::list<Booking> &uBookingsVec, std::list<Booking> &bookingsVec );
    void addCustomer( Person person, std::list<Customer> &cusVec );
    static bool checkIfDateAvailable( int days, Room& room, Date dateStart, std::list<Booking> &bookingsVec );
    void removeEquipment ( Room& room, int index );

    template <class T>
    void addEquipment( Room& room, T equipment )
    {
        room.getEquipment().push_back( std::make_shared<T>( equipment ) );
    }

protected:

private:
};

#endif // RECEPTIONIST_HPP
