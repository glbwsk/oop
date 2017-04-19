#include <boost/test/unit_test.hpp>
#include "Hotel.hpp"
#include "IHotelCLI.hpp"

#include <iostream>

using namespace std;

//#define HotelTest
#ifdef HotelTest

/* Unit tests for Hotel.hpp */

/* correct */
BOOST_AUTO_TEST_SUITE( HotelSuiteCorrect )

BOOST_AUTO_TEST_CASE( Test1 )
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

    /* dodawanie i lista managerow i zwalnianie */
    hotel.getManagers().at( 0 ).hire<Manager>( Employee(), hotel.getManagers() );
    hotel.getManagers().at( 0 ).hire<Manager>( Employee( Person(), 5000, Date( 21, 04, 1996 ) ), hotel.getManagers() );
    hotel.printManagers();
    hotel.getManagers().at( 0 ).fire<Manager>( hotel.getManagers(), 2 );
    hotel.printManagers();

    /* dodawanie i lista recepcjonistow */
    hotel.getManagers().at( 0 ).hire<Receptionist>( Employee( Person( "Jan", "Jacek" ), 2300 ), hotel.getReceptionists() );
    hotel.getManagers().at( 0 ).hire<Receptionist>( Employee(), hotel.getReceptionists() );
    hotel.printReceptionists();

    /* dodawanie i lista sprzataczy */
    hotel.getManagers().at( 0 ).hire<Cleaner>( Employee( Person( "Twoja", "Mama" ), 500 ), hotel.getCleaners() );
    hotel.getManagers().at( 0 ).hire<Cleaner>( Employee(), hotel.getCleaners() );
    hotel.printCleaners();

    /* dodawanie i lista klientow */
    hotel.getReceptionists().at( 0 ).addCustomer( Person( "Klient", "Numer jeden", "imejl", "12323512", Address( "ulica", "miasto", "23123", 23 ) ), hotel.getCustomers() );
    hotel.getReceptionists().at( 0 ).addCustomer( Person( "Klient", "Numer dwa", "imejl", "12323512", Address( "ulica", "miasto", "23123", 46 ) ), hotel.getCustomers() );
    hotel.printCustomers();

    /* dodawanie i lista rezerwacji, potwierdzanie rezerwacji, sprawdzanie stanu pokojow i pieter*/
    auto itc = hotel.getCustomers().begin();
    std::advance( itc, 0 ); //customer 0
    ( *itc ).book( 5, hotel.getFloors().at( 0 ).getRooms().at( 1 ), Date( 8, 01, 2016 ) + 52, hotel.getUnconfirmedBookings() );
    std::advance( itc, 1 ); //customer 1
    ( *itc ).book( 7, hotel.getFloors().at( 0 ).getRooms().at( 0 ), Date(), hotel.getUnconfirmedBookings() );
    hotel.getReceptionists().at( 0 ).bookUnconfirmed( hotel.getUnconfirmedBookings(), hotel.getBookings() );

    /* dokonanie platnosci */
    auto itb = hotel.getBookings().begin();
    std::advance( itb, 0 ); //boooking 0
    std::advance( itc, -1 ); //customer 0
    ( *itc ).pay( *itb, 500 );
    ( *itc ).pay( *itb, 490 );
    std::advance( itb, 1 ); //booking 1
    std::advance( itc, 1 ); //customer 1
    ( *itc ).pay( *itb, 400 );
    hotel.printBookings( hotel.getBookings() );

    /* czyszczenie pokoju i pietra*/
    hotel.getCleaners().at( 0 ).cleanFloor( hotel.getFloors().at( 1 ) );
    hotel.getCleaners().at( 1 ).cleanRoom( hotel.getFloors().at( 0 ).getRooms().at( 0 ) );

    /* dodawanie nowych pieter i pokojow *
    hotel.addFloor();
    hotel.addFloor();
    hotel.addFloor();
    hotel.addRoom();
    hotel.addRoom();
    hotel.addRoom();
    hotel.printFloors();
    /* ***** */

    hotel.printFloors();

    /* blokada rezerwowania */
    std::advance( itc, -1 ); //customer 0
    ( *itc ).book ( 3, hotel.getFloors().at( 0 ).getRooms().at( 1 ), Date( 27, 02, 2016 ), hotel.getUnconfirmedBookings() );
    ( *itc ).book ( 3, hotel.getFloors().at( 0 ).getRooms().at( 1 ), Date( 26, 02, 2016 ), hotel.getUnconfirmedBookings() );
    ( *itc ).book ( 3, hotel.getFloors().at( 0 ).getRooms().at( 1 ), Date( 4, 03, 2016 ), hotel.getUnconfirmedBookings() );
    ( *itc ).book ( 3, hotel.getFloors().at( 0 ).getRooms().at( 1 ), Date( 5, 03, 2016 ), hotel.getUnconfirmedBookings() );
    hotel.getReceptionists().at( 0 ).bookUnconfirmed( hotel.getUnconfirmedBookings(), hotel.getBookings() );
    hotel.printBookings( hotel.getBookings() );
    hotel.printBookings( hotel.getUnconfirmedBookings() );
    /* ***** */

    /* adresy payment i bill */
    std::advance( itb, -1 ); //booking 0
    std::cout << std::endl << "Adres bill w bill: " << &( *itb ).getBill() << std::endl;
    std::cout << std::endl << "Adres bill w payment: " << ( *itb ).getBill().getPayment().getBillPtr() << std::endl;
    std::advance( itb, 1 ); //booking 1
    std::cout << std::endl << "Adres bill w bill: " << &( *itb ).getBill() << std::endl;
    std::cout << std::endl << "Adres bill w payment: " << ( *itb ).getBill().getPayment().getBillPtr() << std::endl;
    /* ***** */


    while( true )
        hotel.menu();
}

BOOST_AUTO_TEST_SUITE_END()

#endif
