#ifndef HOTEL_HPP
#define HOTEL_HPP

#include "Manager.hpp"
#include "Receptionist.hpp"
#include "Cleaner.hpp"
#include "Customer.hpp"
#include "Booking.hpp"
#include "Floor.hpp"
#include "IHotel.hpp"

#include <vector>
#include <list>

class Hotel
{
public:
    Hotel( IHotel* iHotel );
    virtual ~Hotel() = default;

    void menu();
    void checkAuth();
    void printHireMenu();
    void printFireMenu();

    void addFloor();
    void addRoom();
    void addBooking( Customer* customer );
    void addPayment( Customer* customer );
    void addClean( Cleaner& cleaner, bool roomOnly );
    void addEquipment( Receptionist& receptionist );

    void printManagers();
    void printReceptionists();
    void printCleaners();
    void printCustomers();
    void printBookings( std::list<Booking> bookings );
    void printCustomerBookings( std::vector<Booking*> bookings );
    void printFloors();

    std::vector<Manager>& getManagers();
    std::vector<Receptionist>& getReceptionists();
    std::vector<Cleaner>& getCleaners();
    std::list<Customer>& getCustomers();
    std::list<Booking>& getBookings();
    std::list<Booking>& getUnconfirmedBookings();
    std::vector<Floor>& getFloors();

protected:

private:
    std::vector<Manager> managers;
    std::vector<Receptionist> receptionists;
    std::vector<Cleaner> cleaners;
    std::list<Customer> customers;
    std::list<Booking> bookings;
    std::list<Booking> unconfirmedBookings;
    std::vector<Floor> floors;

    IHotel* iHotel;

    bool logged;
    int logType;
    unsigned int logID;
};

#endif // HOTEL_HPP
