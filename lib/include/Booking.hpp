#ifndef BOOKING_HPP
#define BOOKING_HPP

#include "Date.hpp"
#include "Bill.hpp"
#include "Room.hpp"
class Customer;

class Booking
{
public:
    Booking( int days,
             Room& room,
             Customer& customer,
             Date dateStart = Date(),
             bool state = true );
    virtual ~Booking() = default;

    // getters & setters
    int getID();
    int getDays();
    void setDays( int val );
    Room& getRoom();
    void setRoom( Room& val );
    Customer& getCustomer();
    void setCustomer( Customer& val );
    Date getDateStart();
    void setDateStart( Date val );
    Date getDateEnd();
    void setDateEnd( Date val );
    bool getState();
    void setState( bool val );
    Bill& getBill();


protected:

private:
    int ID;
    int days;
    Room& room;
    Customer& customer;
    Date dateStart;
    Date dateEnd;
    bool state;
    Bill bill;

    static int autoID;
};

#endif // BOOKING_HPP
