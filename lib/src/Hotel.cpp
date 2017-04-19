#include "Hotel.hpp"
#include "Address.hpp"
#include "Equipment.hpp"

#define MANAGER 1
#define RECEPTIONIST 2
#define CLEANER 3
#define CUSTOMER 4

Hotel::Hotel( IHotel* iHotel )
{
    this->iHotel = iHotel;

    Manager defaultManager( Employee( Person( "Jan", "Janowicz", "abc@hotel.com", "555-555-100",
                                      Address( "Lodzka 315", "Lodz", "93-333", 15 ) ) ) );
    getManagers().push_back( defaultManager );

    logged = false;
}

void Hotel::menu()
{
    while ( !logged )
    {
        logType = iHotel->printLoginScreen();
        logID = iHotel->printAuthScreen();
        logged = true;
        checkAuth();
    }

    switch( logType )
    {
    case MANAGER:
        switch( iHotel->printManagerMenu( getManagers().at( logID ) ) )
        {
        case 1:
            printManagers();
            break;
        case 2:
            printReceptionists();
            break;
        case 3:
            printCleaners();
            break;
        case 4:
            printCustomers();
            break;
        case 5:
            printBookings( bookings );
            break;
        case 6:
            printFloors();
            break;
        case 7:
            printHireMenu();
            break;
        case 8:
            printFireMenu();
            break;
        case 9:
            addFloor();
            break;
        case 10:
            addRoom();
            break;
        case 11:
            logged = false;
            break;
        default:
            break;
        }
        break;
    case RECEPTIONIST:
        switch( iHotel->printReceptionistMenu( getReceptionists().at( logID ) ) )
        {
        case 1:
            printCustomers();
            break;
        case 2:
            printBookings( bookings );
            break;
        case 3:
            printBookings( unconfirmedBookings );
            break;
        case 4:
            getReceptionists().at( logID ).bookUnconfirmed( unconfirmedBookings, bookings );
            iHotel->printOK();
            break;
        case 5:
            addEquipment( getReceptionists().at( logID ) );
            break;
        case 6:
            logged = false;
            break;
        default:
            break;
        }
        break;
    case CLEANER:
        switch( iHotel->printCleanerMenu( getCleaners().at( logID ) ) )
        {
        case 1:
            printFloors();
            break;
        case 2:
            addClean( getCleaners().at( logID ), false );
            break;
        case 3:
            addClean( getCleaners().at( logID ), true );
            break;
        case 4:
            logged = false;
            break;
        default:
            break;
        }
        break;
    case CUSTOMER:
    {
        auto it = getCustomers().begin();
        std::advance( it, logID );
        switch( iHotel->printCustomerMenu( *it ) )
        {
        case 1:
            printCustomerBookings( it->getBookings() );
            break;
        case 2:
            addBooking( &( *it ) );
            break;
        case 3:
            addPayment( &( *it ) );
            break;
        case 4:
            logged = false;
            break;
        default:
            break;
        }
        break;
    }
    default:
        logged = false;
        break;
    }
}

void Hotel::checkAuth()
{
    switch( logType )
    {
    case MANAGER:
        if ( logID >= managers.size() )
        {
            logged = false;
        }
        break;
    case RECEPTIONIST:
        if ( logID >= receptionists.size() )
        {
            logged = false;
        }
        break;
    case CLEANER:
        if ( logID >= cleaners.size() )
        {
            logged = false;
        }
        break;
    case CUSTOMER:
        if ( logID >= customers.size() )
        {
            logged = false;
        }
        break;
    default:
        break;
    }
}

void Hotel::printHireMenu()
{
    switch( iHotel->printManagerHireFire() )
    {
    case MANAGER:
        getManagers().at( logID ).hire<Manager>( iHotel->addNewEmployee(), managers );
        break;
    case RECEPTIONIST:
        getManagers().at( logID ).hire<Receptionist>( iHotel->addNewEmployee(), receptionists );
        break;
    case CLEANER:
        getManagers().at( logID ).hire<Cleaner>( iHotel->addNewEmployee(), cleaners );
        break;
    }
}

void Hotel::printFireMenu()
{
    switch( iHotel->printManagerHireFire() )
    {
    case MANAGER:
        if ( getManagers().at( logID ).fire<Manager>( managers, iHotel->readIndex() ) )
        {
            iHotel->printOK();
        }
        else
        {
            iHotel->printFail();
        }
        break;
    case RECEPTIONIST:
        if ( getManagers().at( logID ).fire<Receptionist>( receptionists, iHotel->readIndex() ) )
        {
            iHotel->printOK();
        }
        else
        {
            iHotel->printFail();
        }
        break;
    case CLEANER:
        if ( getManagers().at( logID ).fire<Cleaner>( cleaners, iHotel->readIndex() ) )
        {
            iHotel->printOK();
        }
        else
        {
            iHotel->printFail();
        }
    }
}

void Hotel::addFloor()
{
    Floor newFloor = iHotel->addNewFloor();
    bool existsFloor = false;

    for ( auto it : floors )
    {
        if ( it.getNumber() == newFloor.getNumber() )
        {
            existsFloor = true;
            break;
        }
    }

    if( existsFloor )
    {
        iHotel->printFail();
    }
    else
    {
        floors.push_back( newFloor );
        iHotel->printOK();
    }
}

void Hotel::addRoom()
{
    Room newRoom = iHotel->addNewRoom();
    bool existsFloor = false;
    bool existsRoom = false;
    int floorIndex = 0;

    for ( auto it : floors )
    {
        if ( it.getNumber() == newRoom.getFloorNumber() )
        {
            existsFloor = true;
            break;
        }
        floorIndex++;
    }

    if ( existsFloor )
    {
        for ( auto it : floors.at( floorIndex ).getRooms() )
        {
            if ( it.getNumber() == newRoom.getNumber() )
            {
                existsRoom = true;
                break;
            }
        }
    }

    if ( existsFloor && !existsRoom )
    {
        floors.at( floorIndex ).getRooms().push_back( newRoom );
        iHotel->printOK();
    }
    else
    {
        iHotel->printFail();
    }

}

void Hotel::addBooking( Customer* customer )
{
    Date dateS;
    int days, floorNum, roomNum, roomIndex = 0, floorIndex = 0;

    iHotel->readBookingData( days, floorNum, roomNum, dateS );

    bool existsFloor = false;
    bool existsRoom = false;

    for ( auto it : floors )
    {
        if ( it.getNumber() == floorNum )
        {
            existsFloor = true;
            break;
        }
        floorIndex++;
    }

    if ( existsFloor )
    {
        for ( auto it : floors.at( floorIndex ).getRooms() )
        {
            if ( it.getNumber() == roomNum )
            {
                existsRoom = true;
                break;
            }
            roomIndex++;
        }
    }

    if ( existsFloor && existsRoom )
    {
        if  ( Receptionist::checkIfDateAvailable( days, floors.at( floorIndex ).getRooms().at( roomIndex ), dateS, bookings ) )
        {
            customer->book( days, floors.at( floorIndex ).getRooms().at( roomIndex ), dateS, unconfirmedBookings );
            iHotel->printOK();
        }
        else
        {
            iHotel->printFail();
        }
    }
    else
    {
        iHotel->printFail();
    }
}

void Hotel::addPayment( Customer* customer )
{
    int id, amount, bookingIndex = 0;
    bool existsID = false;


    iHotel->readPaymentData( id, amount );

    auto it = bookings.begin();
    for( it = bookings.begin(); it != bookings.end(); ++it )
    {
        if ( it->getID() == id && &it->getCustomer() == customer )
        {
            existsID = true;
            break;
        }
        bookingIndex++;
    }

    if ( existsID )
    {
        if ( customer->pay( *it, amount ) )
        {
            iHotel->printOK();
        }
        else
        {
            iHotel->printFail();
        }
    }
    else
    {
        iHotel->printFail();
    }
}

void Hotel::addClean( Cleaner& cleaner, bool roomOnly )
{
    int floorNum, roomNum, floorIndex, roomIndex;
    bool existsFloor = false;
    bool existsRoom = false;

    iHotel->readFloorAndRoom( floorNum, roomNum, roomOnly );

    for ( auto it : floors )
    {
        if ( it.getNumber() == floorNum )
        {
            existsFloor = true;
            break;
        }
        floorIndex++;
    }

    if ( existsFloor && roomOnly )
    {
        for ( auto it : floors.at( floorIndex ).getRooms() )
        {
            if ( it.getNumber() == roomNum )
            {
                existsRoom = true;
                break;
            }
            roomIndex++;
        }
    }

    if ( existsFloor && !roomOnly )
    {
        cleaner.cleanFloor( floors.at( floorIndex ) );
        iHotel->printOK();
    }
    else if ( existsFloor && existsRoom && roomOnly )
    {
        cleaner.cleanRoom( floors.at( floorIndex ).getRooms().at( roomIndex ) );
        iHotel->printOK();
    }
    else
    {
        iHotel->printFail();
    }
}

void Hotel::addEquipment( Receptionist& receptionist )
{
    int floorNum, roomNum, floorIndex, roomIndex;
    bool existsFloor = false;
    bool existsRoom = false;

    iHotel->readFloorAndRoom( floorNum, roomNum, true );

    for ( auto it : floors )
    {
        if ( it.getNumber() == floorNum )
        {
            existsFloor = true;
            break;
        }
        floorIndex++;
    }

    if ( existsFloor )
    {
        for ( auto it : floors.at( floorIndex ).getRooms() )
        {
            if ( it.getNumber() == roomNum )
            {
                existsRoom = true;
                break;
            }
            roomIndex++;
        }
    }

    if ( existsFloor && existsRoom )
    {

        switch ( iHotel->printEquAddMenu() )
        {
        case 1:
        {
            TV e;
            e.read( iHotel );
            receptionist.addEquipment( floors.at( floorIndex ).getRooms().at( roomIndex ), e );
            iHotel->printOK();
            break;
        }
        case 2:
        {
            Bed e;
            e.read( iHotel );
            receptionist.addEquipment( floors.at( floorIndex ).getRooms().at( roomIndex ), e );
            iHotel->printOK();
            break;
        }
        case 3:
        {
            Sheets e;
            e.read( iHotel );
            receptionist.addEquipment( floors.at( floorIndex ).getRooms().at( roomIndex ), e );
            iHotel->printOK();
            break;
        }
        case 4:
        {
            unsigned int index = iHotel->readIndex();

            if ( index >= floors.at( floorIndex ).getRooms().at( roomIndex ).getEquipment().size() )
            {
                iHotel->printFail();
                break;
            }
            else
            {
                receptionist.removeEquipment( floors.at( floorIndex ).getRooms().at( roomIndex ), index );
                iHotel->printOK();
            }
            break;
        }
        default:
            iHotel->printFail();
            break;
        }
    }
    else
    {
        iHotel->printFail();
    }
}

void Hotel::printManagers()
{
    iHotel->printAllManagers( managers );
}

void Hotel::printReceptionists()
{
    iHotel->printAllReceptionists( receptionists );
}

void Hotel::printCleaners()
{
    iHotel->printAllCleaners( cleaners );
}

void Hotel::printCustomers()
{
    iHotel->printAllCustomers( customers );
}

void Hotel::printBookings( std::list<Booking> bookings )
{
    iHotel->printAllBookings( bookings );
}

void Hotel::printCustomerBookings( std::vector<Booking*> bookings )
{
    iHotel->printAllCustomerBookings( bookings );
}

void Hotel::printFloors()
{
    iHotel->printAllFloors( floors );
}

std::vector<Manager>& Hotel::getManagers()
{
    return managers;
}

std::vector<Receptionist>& Hotel::getReceptionists()
{
    return receptionists;
}

std::vector<Cleaner>& Hotel::getCleaners()
{
    return cleaners;
}

std::list<Customer>& Hotel::getCustomers()
{
    return customers;
}

std::list<Booking>& Hotel::getBookings()
{
    return bookings;
}

std::list<Booking>& Hotel::getUnconfirmedBookings()
{
    return unconfirmedBookings;
}

std::vector<Floor>& Hotel::getFloors()
{
    return floors;
}

