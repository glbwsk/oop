#ifndef IHOTELCLI_HPP
#define IHOTELCLI_HPP

#include "IHotel.hpp"

class IHotelCLI : public IHotel
{
public:
    IHotelCLI() = default;
    virtual ~IHotelCLI() = default;

    /* HOTEL INTERFACE */
    virtual int printLoginScreen() override;
    virtual int printAuthScreen() override;
    virtual int printManagerMenu( Manager manager ) override;
    virtual int readIndex() override;
    virtual int printManagerHireFire() override;

    virtual int printReceptionistMenu( Receptionist receptionist ) override;
    virtual int printCleanerMenu( Cleaner cleaner ) override;
    virtual int printCustomerMenu( Customer customer ) override;

    virtual int printEquAddMenu() override;
    virtual void printEquipment( std::vector<std::shared_ptr<Equipment>> equipment ) override;

    virtual void printOK() override;
    virtual void printFail() override;

    virtual Person addNewPerson() override;
    virtual Employee addNewEmployee() override;
    virtual Floor addNewFloor() override;
    virtual Room addNewRoom() override;

    virtual void readBookingData( int& days, int& floorNum, int& roomNum, Date& dateStart ) override;
    virtual void readPaymentData( int& id, int& amount ) override;
    virtual void readFloorAndRoom( int& floorNum, int& roomNum, bool onlyRoom ) override;

    virtual void readTvData( TV* e ) override;
    virtual void readBedData( Bed* e ) override;
    virtual void readSheetsData( Sheets* e ) override;

    virtual void printAllManagers( std::vector<Manager> managersVec ) override;
    virtual void printAllReceptionists( std::vector<Receptionist> receptionistsVec ) override;
    virtual void printAllCleaners( std::vector<Cleaner> cleanersVec ) override;
    virtual void printAllCustomers( std::list<Customer> customersVec ) override;
    virtual void printAllBookings( std::list<Booking> bookingsVec ) override;
    virtual void printAllCustomerBookings( std::vector<Booking*> bookingsVec ) override;
    virtual void printAllFloors( std::vector<Floor> floorsVec ) override;
    /* *************** */

    virtual void printPerson( Person p ) override;
    virtual void printBooking ( Booking b ) override;
    virtual void printFloor ( Floor f ) override;
    virtual void printRoom ( Room r ) override;
    virtual void printTV ( TV e ) override;
    virtual void printBed ( Bed e ) override;
    virtual void printSheets ( Sheets e ) override;

    template <class val>
    val readVal();

    bool readAnswer();
    std::string readLine();

protected:

private:
};

#endif // IHOTELCLI_HPP
