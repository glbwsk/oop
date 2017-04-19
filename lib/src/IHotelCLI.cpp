#include "IHotelCLI.hpp"

#include <iostream>
#include <cstdlib>
#include <ExceptionCin.hpp>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

int IHotelCLI::printLoginScreen()
{
    std::system( CLEAR );

    std::cout << "\n\n--------\n";
    std::cout << "Log as : ";
    std::cout << "\n--------\n";

    std::cout << "1 - manager" << std::endl;
    std::cout << "2 - receptionist" << std::endl;
    std::cout << "3 - cleaner" << std::endl;
    std::cout << "4 - customer" << std::endl;

    std::cout << "\nOption number: ";
    return readVal<int>();
}

int IHotelCLI::printAuthScreen()
{
    std::cout << "\nGive your ID: ";

    return readVal<int>();
}

int IHotelCLI::printManagerMenu( Manager manager )
{

    std::cout << "\n\n--------\n";
    std::cout << "Logged as : " << manager.getName()
              << " " << manager.getSurname();
    std::cout << "\n--------\n";

    std::cout << "1 - print all managers" << std::endl;
    std::cout << "2 - print all receptionists" << std::endl;
    std::cout << "3 - print all cleaners" << std::endl;
    std::cout << "4 - print all customers" << std::endl;
    std::cout << "5 - print all bookings" << std::endl;
    std::cout << "6 - print all floors" << std::endl;
    std::cout << "7 - hire" << std::endl;
    std::cout << "8 - fire" << std::endl;
    std::cout << "9 - add new floor" << std::endl;
    std::cout << "10 - add new room" << std::endl;
    std::cout << "11 - log out" << std::endl;

    std::cout << "\nOption number: ";

    return readVal<int>();
}

int IHotelCLI::readIndex()
{
    std::cout << "\nGive index: ";

    return readVal<int>();
}

int IHotelCLI::printManagerHireFire()
{
    std::cout << "\nHIRE/FIRE: \n";

    std::cout << "1 - manager" << std::endl;
    std::cout << "2 - receptionist" << std::endl;
    std::cout << "3 - cleaner" << std::endl;

    std::cout << "\nOption number: ";

    return readVal<int>();
}

int IHotelCLI::printReceptionistMenu( Receptionist receptionist )
{

    std::cout << "\n\n--------\n";
    std::cout << "Logged as : " << receptionist.getName()
              << " " << receptionist.getSurname();
    std::cout << "\n--------\n";

    std::cout << "1 - print all customers" << std::endl;
    std::cout << "2 - print all confirmed bookings" << std::endl;
    std::cout << "3 - print all unconfirmed bookings" << std::endl;
    std::cout << "4 - confirm new bookings" << std::endl;
    std::cout << "5 - add room equipment" << std::endl;
    std::cout << "6 - log out" << std::endl;

    std::cout << "\nOption number: ";

    return readVal<int>();
}

int IHotelCLI::printCleanerMenu( Cleaner cleaner )
{

    std::cout << "\n\n--------\n";
    std::cout << "Logged as : " << cleaner.getName()
              << " " << cleaner.getSurname();
    std::cout << "\n--------\n";

    std::cout << "1 - print all floors" << std::endl;
    std::cout << "2 - clean floor" << std::endl;
    std::cout << "3 - clean room" << std::endl;
    std::cout << "4 - log out" << std::endl;

    std::cout << "\nOption number: ";

    return readVal<int>();
}

int IHotelCLI::printCustomerMenu( Customer customer )
{

    std::cout << "\n\n--------\n";
    std::cout << "Logged as : " << customer.getName()
              << " " << customer.getSurname();
    std::cout << "\n--------\n";

    std::cout << "1 - print my confirmed bookings" << std::endl;
    std::cout << "2 - book" << std::endl;
    std::cout << "3 - pay" << std::endl;
    std::cout << "4 - log out" << std::endl;

    std::cout << "\nOption number: ";

    return readVal<int>();
}

int IHotelCLI::printEquAddMenu()
{
    std::cout << "\n\n ADDING NEW EQUIPMENT \n\n";

    std::cout << "1 - TV" << std::endl;
    std::cout << "2 - Bed" << std::endl;
    std::cout << "3 - Sheets" << std::endl;
    std::cout << "4 - Remove equipment" << std::endl;

    std::cout << "\nOption number: ";

    return readVal<int>();
}

void IHotelCLI::printEquipment( std::vector<std::shared_ptr<Equipment>> equipment )
{
    int eqNumber = 0;

    for ( auto i : equipment )
    {
        std::cout << "\n\n--" << eqNumber++ << "--\n";
        i->print( this );
    }

    std::cout << "\n\n";
}

void IHotelCLI::printOK()
{
    std::cout << "\n\nAction succeeded.\n\n";
}

void IHotelCLI::printFail()
{
    std::cout << "\n\nAction failed! Check input data and try again.\n\n";
}

Person IHotelCLI::addNewPerson()
{
    Person newPerson;

    std::cout << "\nAdd address? (y/n): ";
    if ( readAnswer() )
    {
        Address address;

        std::cout << "\nStreet: ";
        address.setStreet( readLine() );
        std::cout << "\nCity: ";
        address.setCity( readLine() );
        std::cout << "\nPostal code: ";
        address.setPostalCode( readVal<std::string>() );
        std::cout << "\nApartment number: ";
        address.setApartmentNum( readVal<int>() );

        newPerson.setAddres( address );
    }

    std::cout << "\nName: ";
    newPerson.setName( readLine() );
    std::cout << "\nSurname: ";
    newPerson.setSurname( readLine() );
    std::cout << "\nEmail: ";
    newPerson.setEmail( readVal<std::string>() );
    std::cout << "\nTelephone number: ";
    newPerson.setTelNumber( readVal<std::string>() );

    return newPerson;
}

Employee IHotelCLI::addNewEmployee()
{
    std::cout << "\n ADDING NEW EMPLOYEE \n";

    Person p = addNewPerson();
    Employee newEmployee( p );
    std::cout << "\nSalary: ";
    newEmployee.setSalary( readVal<int>() );
    std::cout << "\nAdd employ date? (y/n): ";
    if ( readAnswer() )
    {
        Date date;

        std::cout << "\nDay: ";
        date.setDay( readVal<int>() );
        std::cout << "\nMonth: ";
        date.setMonth( readVal<int>() );
        std::cout << "\nYear: ";
        date.setYear( readVal<int>() );

        newEmployee.setEmployDate( date );
    }

    return newEmployee;
}

Floor IHotelCLI::addNewFloor()
{
    int number;

    std::cout << "\n ADDING NEW FLOOR \n";
    std::cout << "\nFloor number: ";
    number = readVal<int>();

    Floor newFloor ( number );

    return newFloor;
}

Room IHotelCLI::addNewRoom()
{
    int floorNumber, roomNumber;

    std::cout << "\n ADDING NEW ROOM \n";
    std::cout << "\nFloor number: ";
    floorNumber = readVal<int>();

    std::cout << "\nRoom number: ";
    roomNumber = readVal<int>();

    Room newRoom ( roomNumber, floorNumber );

    std::cout << "\nAdd price per day? (y/n): ";
    if ( readAnswer() )
    {
        std::cout << "\nPrice per day: ";
        newRoom.setPricePerDay( readVal<int>() );
    }

    return newRoom;
}

void IHotelCLI::readBookingData( int& days, int& floorNum, int& roomNum, Date& dateStart )
{
    std::cout << "\n ADDING NEW BOOKING \n";

    std::cout << "\nFloor number: ";
    floorNum = readVal<int>();

    std::cout << "\nRoom number: ";
    roomNum = readVal<int>();

    std::cout << "\nDate start: ";
    std::cout << "\nDay: ";
    dateStart.setDay( readVal<int>() );
    std::cout << "\nMonth: ";
    dateStart.setMonth( readVal<int>() );
    std::cout << "\nYear: ";
    dateStart.setYear( readVal<int>() );

    std::cout << "\nHow many days: ";
    days = readVal<int>();
}

void IHotelCLI::readPaymentData( int& id, int& amount )
{
    std::cout << "\n PAYMENT \n";

    std::cout << "\nBooking ID: ";
    id = readVal<int>();

    std::cout << "\nAmount: ";
    amount = readVal<int>();
}

void IHotelCLI::readFloorAndRoom( int& floorNum, int& roomNum, bool onlyRoom )
{
    std::cout << "\nFloor number: ";
    floorNum = readVal<int>();

    if ( onlyRoom )
    {
        std::cout << "\nRoom number: ";
        roomNum = readVal<int>();
    }
}

void IHotelCLI::readTvData( TV* e )
{
    std::cout << "\nSize: ";
    int size = readVal<int>();
    std::cout << "\nType: ";
    std::string type = readVal<std::string>();

    e->setSize( size );
    e->setType( type );
}

void IHotelCLI::readBedData( Bed* e )
{
    std::cout << "\nCapacity: ";
    int capacity = readVal<int>();
    std::cout << "\nType: ";
    std::string type = readVal<std::string>();

    e->setCapacity( capacity );
    e->setType( type );
}

void IHotelCLI::readSheetsData( Sheets* e )
{
    std::cout << "\nColour: ";
    std::string colour = readVal<std::string>();
    std::cout << "\nPattern: ";
    std::string pattern = readVal<std::string>();

    e->setColour( colour );
    e->setPattern( pattern );
}

void IHotelCLI::printPerson( Person p )
{
    std::cout << "\nName: " << p.getName();
    std::cout << "\nSurname: " << p.getSurname();
    std::cout << "\nStreet: " << p.getAddress().getStreet();
    std::cout << "\nApartment number: " << p.getAddress().getApartmentNum();
    std::cout << "\nCity: " << p.getAddress().getCity();
    std::cout << "\nPostal code: " << p.getAddress().getPostalCode();
    std::cout << "\nEmail: " << p.getEmail();
    std::cout << "\nTelephone number: " << p.getTelNumber();
}

void IHotelCLI::printBooking ( Booking b )
{
    std::cout << "\nID: " << b.getID();
    std::cout << "\nDays: " << b.getDays();
    std::cout << "\nDate Start: " << b.getDateStart().getDay()
              << "-" << b.getDateStart().getMonth() << "-" << b.getDateStart().getYear();
    std::cout << "\nRoom: " << b.getRoom().getNumber();
    std::cout << "\nCustomer: " << b.getCustomer().getName() << " " << b.getCustomer().getSurname();

    std::cout << "\nConfirmed?: ";
    if ( b.getState() )
        std::cout << "YES";
    else
        std::cout << "NO";

    std::cout << "\n\n\tBILL:";
    std::cout << "\n\tAmount: " << b.getBill().getAmount();

    std::cout << "\n\n\t\tPAYMENT:";
    std::cout << "\n\t\tAmount Paid: " << b.getBill().getPayment().getAmountPaid();
    std::cout << "\n\t\tDate Paid: " << b.getBill().getPayment().getDatePaid().getDay()
              << "-" << b.getBill().getPayment().getDatePaid().getMonth() << "-"
              << b.getBill().getPayment().getDatePaid().getYear();

    std::cout << "\n\t\tIs Paid Fully?: ";
    if ( b.getBill().getPayment().isPaid() )
        std::cout << "YES";
    else
        std::cout << "NO";
}

void IHotelCLI::printFloor ( Floor f )
{
    std::cout << "\nFloor number: " << f.getNumber();
    std::cout << "\nDate Cleaned: " << f.getDateCleaned().getDay()
              << "-" << f.getDateCleaned().getMonth() << "-" << f.getDateCleaned().getYear();

    int roomNumber = 0;
    std::cout << "\n\nRooms on this floor:";

    for ( unsigned int i = 0; i < f.getRooms().size(); ++i )
    {
        std::cout << "\n\n----" << roomNumber << "----\n";
        printRoom( f.getRooms()[i] );
        roomNumber++;
    }
}

void IHotelCLI::printRoom ( Room r )
{
    std::cout << "\nNumber: " << r.getNumber();
    std::cout << "\nPrice per day: " << r.getPricePerDay();
    std::cout << "\nDate Cleaned: " << r.getDateCleaned().getDay()
              << "-" << r.getDateCleaned().getMonth() << "-" << r.getDateCleaned().getYear();

    std::cout << "\n\nEquipment: ";
    printEquipment( r.getEquipment() );
}

void IHotelCLI::printTV( TV e )
{
    std::cout << "\nTV: ";
    std::cout << "\nSize: " << e.getSize();
    std::cout << "\nType: " << e.getType();
}

void IHotelCLI::printBed( Bed e )
{
    std::cout << "\nBed: ";
    std::cout << "\nCapacity: " << e.getCapacity();
    std::cout << "\nType: " << e.getType();
}

void IHotelCLI::printSheets( Sheets e )
{
    std::cout << "\nSheets: ";
    std::cout << "\nColour:  " << e.getColour();
    std::cout << "\nPattern: " << e.getPattern();
}

void IHotelCLI::printAllManagers( std::vector<Manager> managersVec )
{
    int personNumber = 0;

    std::cout << "\n ALL MANAGERS:";

    for ( auto i : managersVec )
    {
        std::cout << "\n\n--------" << personNumber << "--------\n";

        printPerson( i );
        std::cout << "\nSalary: " << i.getSalary();
        std::cout << "\nEmploy date: " << i.getEmployDate().getDay()
                  << "-" << i.getEmployDate().getMonth() << "-" << i.getEmployDate().getYear();

        personNumber++;
    }

    std::cout << "\n\n";
}

void IHotelCLI::printAllReceptionists( std::vector<Receptionist> receptionistsVec )
{
    int personNumber = 0;

    std::cout << "\n ALL RECEPTIONISTS:";

    for ( auto i : receptionistsVec )
    {
        std::cout << "\n\n--------" << personNumber << "--------\n";

        printPerson( i );
        std::cout << "\nSalary: " << i.getSalary();
        std::cout << "\nEmploy date: " << i.getEmployDate().getDay()
                  << "-" << i.getEmployDate().getMonth() << "-" << i.getEmployDate().getYear();

        personNumber++;
    }

    std::cout << "\n\n";
}

void IHotelCLI::printAllCleaners( std::vector<Cleaner> cleanersVec )
{
    int personNumber = 0;

    std::cout << "\n ALL CLEANERS:";

    for ( auto i : cleanersVec )
    {
        std::cout << "\n\n--------" << personNumber << "--------\n";

        printPerson( i );
        std::cout << "\nSalary: " << i.getSalary();
        std::cout << "\nEmploy date: " << i.getEmployDate().getDay()
                  << "-" << i.getEmployDate().getMonth() << "-" << i.getEmployDate().getYear();

        personNumber++;
    }

    std::cout << "\n\n";
}

void IHotelCLI::printAllCustomers( std::list<Customer> customersVec )
{
    int personNumber = 0;

    std::cout << "\n ALL CUSTOMERS:";

    for ( auto i : customersVec )
    {
        std::cout << "\n\n--------" << personNumber << "--------\n";
        printPerson( i );
        personNumber++;
    }

    std::cout << "\n\n";
}

void IHotelCLI::printAllBookings( std::list<Booking> bookingsVec )
{
    int bookingNumber = 0;

    std::cout << "\n ALL BOOKINGS:";

    for ( auto i : bookingsVec )
    {
        std::cout << "\n\n--------" << bookingNumber << "--------\n";
        printBooking( i );
        bookingNumber++;
    }

    std::cout << "\n\n";
}

void IHotelCLI::printAllCustomerBookings( std::vector<Booking*> bookingsVec )
{
    int bookingNumber = 0;

    std::cout << "\n ALL BOOKINGS:";

    for ( unsigned int i = 0; i < bookingsVec.size(); ++i )
    {
        std::cout << "\n\n--------" << bookingNumber << "--------\n";
        printBooking( *( bookingsVec[i] ) );
        bookingNumber++;
    }

    std::cout << "\n\n";
}

void IHotelCLI::printAllFloors( std::vector<Floor> floorsVec )
{
    int floorNumber = 0;

    std::cout << "\n ALL FLOORS:";

    for ( unsigned int i = 0; i < floorsVec.size(); ++i )
    {
        std::cout << "\n\n--------" << floorNumber << "--------\n";
        printFloor( ( floorsVec[i] ) );
        floorNumber++;
    }

    std::cout << "\n\n";
}

template <class val>
val IHotelCLI::readVal()
{
    val value;

    try
    {
        std::cin >> value;
        if ( !std::cin.good() || std::cin.fail() )
        {
            throw excin::ExceptionCin();
        }
    }
    catch( excin::ExceptionCin e )
    {
        std::cin.clear();
        std::cin.sync();
        std::cout << e.what() << std::endl;
        std::cout << e.climsg();
        value = readVal<val>();
    }

    return value;
}

bool IHotelCLI::readAnswer()
{
    char answer;

    std::cin >> answer;
    std::cin.ignore();

    if ( answer == 'y' || answer == 'Y' )
    {
        return true;
    }

    return false;
}

std::string IHotelCLI::readLine()
{
    std::string line;
    std::getline( std::cin, line );
    return line;
}
