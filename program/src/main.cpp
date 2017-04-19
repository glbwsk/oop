#include "Hotel.hpp"
#include "IHotelCLI.hpp"

#include <iostream>

using namespace std;

int main()
{
    IHotelCLI cli;
    IHotel* iHotelPtr = &cli;
    Hotel hotel( iHotelPtr );

    /* poczatkowe pietra, pokoje */
    Floor floor0( 0 );
    Floor floor1( 1 );
    hotel.getFloors().push_back( floor0 );
    hotel.getFloors().push_back( floor1 );
    Room room11( 11, hotel.getFloors().at( 0 ).getNumber() );
    Room room238( 238, hotel.getFloors().at( 0 ).getNumber() );
    Room room333( 333, hotel.getFloors().at( 1 ).getNumber() );
    hotel.getFloors().at( 0 ).getRooms().push_back( room11 );
    hotel.getFloors().at( 0 ).getRooms().push_back( room238 );
    hotel.getFloors().at( 1 ).getRooms().push_back( room333 );
    /* ****************************************************************************************** */

    /* dodawanie managerow i zwalnianie */
    hotel.getManagers().at( 0 ).hire<Manager>( Employee(), hotel.getManagers() );
    hotel.getManagers().at( 0 ).hire<Manager>( Employee( Person(), 5000, Date( 21, 04, 1996 ) ), hotel.getManagers() );
    hotel.getManagers().at( 0 ).fire<Manager>( hotel.getManagers(), 2 );

    /* dodawanie recepcjonistow */
    hotel.getManagers().at( 0 ).hire<Receptionist>( Employee( Person( "Jan", "Jacek" ), 2300 ), hotel.getReceptionists() );
    hotel.getManagers().at( 0 ).hire<Receptionist>( Employee(), hotel.getReceptionists() );

    /* dodawanie sprzataczy */
    hotel.getManagers().at( 0 ).hire<Cleaner>( Employee( Person( "Twoja", "Mama" ), 500 ), hotel.getCleaners() );
    hotel.getManagers().at( 0 ).hire<Cleaner>( Employee(), hotel.getCleaners() );

    /* dodawanie klientow */
    hotel.getReceptionists().at( 0 ).addCustomer( Person( "Klient", "Numer jeden", "imejl", "12323512", Address( "ulica", "miasto", "23123", 23 ) ), hotel.getCustomers() );
    hotel.getReceptionists().at( 0 ).addCustomer( Person( "Klient", "Numer dwa", "imejl", "12323512", Address( "ulica", "miasto", "23123", 46 ) ), hotel.getCustomers() );

    /* czyszczenie pokoju i pietra */
    hotel.getCleaners().at( 0 ).cleanFloor( hotel.getFloors().at( 1 ) );
    hotel.getCleaners().at( 1 ).cleanRoom( hotel.getFloors().at( 0 ).getRooms().at( 0 ) );

    /* dodawanie wyposazenia */
    hotel.getReceptionists().at( 0 ).addEquipment( hotel.getFloors().at( 0 ).getRooms().at( 0 ), TV( 5, "aaa" ) );
    hotel.getReceptionists().at( 0 ).addEquipment( hotel.getFloors().at( 0 ).getRooms().at( 0 ), Bed( 10, "bbb" ) );
    hotel.getReceptionists().at( 0 ).addEquipment( hotel.getFloors().at( 0 ).getRooms().at( 0 ), Sheets( "blue", "dotted" ) );

    hotel.getReceptionists().at( 0 ).addEquipment( hotel.getFloors().at( 1 ).getRooms().at( 0 ), TV( 50, "xxx" ) );
    hotel.getReceptionists().at( 0 ).addEquipment( hotel.getFloors().at( 1 ).getRooms().at( 0 ), Bed( 10, "zzz" ) );
    hotel.getReceptionists().at( 0 ).addEquipment( hotel.getFloors().at( 1 ).getRooms().at( 0 ), Sheets( "black", "xd" ) );

    while( true ) {
        hotel.menu();
    }

    return 0;
}
