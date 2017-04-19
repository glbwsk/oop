#ifndef BILL_HPP
#define BILL_HPP

#include "Payment.hpp"
class Booking;

class Bill
{
public:
    Bill( Booking* booking );

    virtual ~Bill() = default;

    // getters & setters
    int getAmount();
    void setAmount();
    Payment& getPayment();
    void setBookingPtr( Booking* booking );
    Booking* getBookingPtr();

protected:

private:
    int amount;
    Payment payment;
    Booking* booking;
};

#endif // BILL_HPP
