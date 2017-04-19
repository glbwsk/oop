#ifndef IHOTEL_HPP
#define IHOTEL_HPP

#include "Person.hpp"
#include "Manager.hpp"
#include "Receptionist.hpp"
#include "Cleaner.hpp"
#include "Customer.hpp"
#include "Booking.hpp"
#include "Floor.hpp"
#include "TV.hpp"
#include "Bed.hpp"
#include "Sheets.hpp"

#include <vector>
#include <list>
#include <memory>

class IHotel
{
public:
    IHotel() = default;
    virtual ~IHotel() = default;

    /* HOTEL INTERFACE */
    virtual int printLoginScreen() = 0;
    virtual int printAuthScreen() = 0;
    virtual int printManagerMenu( Manager manager ) = 0;
    virtual int readIndex() = 0;
    virtual int printManagerHireFire() = 0;

    virtual int printReceptionistMenu( Receptionist receptionist ) = 0;
    virtual int printCleanerMenu( Cleaner cleaner ) = 0;
    virtual int printCustomerMenu( Customer customer )  = 0;

    virtual int printEquAddMenu() = 0;
    virtual void printEquipment( std::vector<std::shared_ptr<Equipment>> equipment ) = 0;

    virtual void printOK() = 0;
    virtual void printFail() = 0;

    virtual Person addNewPerson() = 0;
    virtual Employee addNewEmployee() = 0;
    virtual Floor addNewFloor() = 0;
    virtual Room addNewRoom() = 0;

    virtual void readBookingData( int& days, int& floorNum, int& roomNum, Date& dateStart ) = 0;
    virtual void readPaymentData( int& id, int& amount ) = 0;
    virtual void readFloorAndRoom( int& floorNum, int& roomNum, bool onlyRoom ) = 0;

    virtual void readTvData( TV* e ) = 0;
    virtual void readBedData( Bed* e ) = 0;
    virtual void readSheetsData( Sheets* e ) = 0;

    virtual void printAllManagers( std::vector<Manager> managersVec ) = 0;
    virtual void printAllReceptionists( std::vector<Receptionist> receptionistsVec ) = 0;
    virtual void printAllCleaners( std::vector<Cleaner> cleanersVec ) = 0;
    virtual void printAllCustomers( std::list<Customer> customersVec ) = 0;
    virtual void printAllBookings( std::list<Booking> bookingsVec ) = 0;
    virtual void printAllCustomerBookings( std::vector<Booking*> bookingsVec ) = 0;
    virtual void printAllFloors( std::vector<Floor> floorsVec ) = 0;

    virtual void printPerson( Person p ) = 0;
    virtual void printBooking ( Booking b ) = 0;
    virtual void printFloor ( Floor f ) = 0;
    virtual void printRoom ( Room r ) = 0;
    virtual void printTV ( TV e ) = 0;
    virtual void printBed ( Bed e ) = 0;
    virtual void printSheets ( Sheets e ) = 0;
    /* *************** */

protected:

private:

};

#endif // IHOTEL_HPP
