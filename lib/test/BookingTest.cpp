#include <boost/test/unit_test.hpp>
#include "Booking.hpp"
#include "Customer.hpp"

/* Unit tests for Booking.hpp */

/* correct */
BOOST_AUTO_TEST_SUITE( BookingSuiteCorrect )

BOOST_AUTO_TEST_CASE( ctor_default )
{
    Room newRoom;
    Customer newCustomer;
    Booking newBooking( 5, newRoom, newCustomer, Date() );
    BOOST_CHECK_EQUAL( newBooking.getID(), 1 );
    BOOST_CHECK_EQUAL( newBooking.getDays(), 5 );
    BOOST_CHECK_EQUAL( &newBooking.getRoom() == &newRoom, true );
    BOOST_CHECK_EQUAL( &newBooking.getCustomer() == &newCustomer, true );
    Date date1;
    BOOST_CHECK_EQUAL( newBooking.getDateStart().getDay(), date1.getDay() );
    BOOST_CHECK_EQUAL( newBooking.getDateStart().getMonth(), date1.getMonth() );
    BOOST_CHECK_EQUAL( newBooking.getDateStart().getYear(), date1.getYear() );
    Date date2 = date1 + 4;
    BOOST_CHECK_EQUAL( newBooking.getDateEnd().getDay(), date2.getDay() );
    BOOST_CHECK_EQUAL( newBooking.getDateEnd().getMonth(), date2.getMonth() );
    BOOST_CHECK_EQUAL( newBooking.getDateEnd().getYear(), date2.getYear() );
    BOOST_CHECK_EQUAL( newBooking.getState(), true );
}

BOOST_AUTO_TEST_CASE( ctor )
{
    Room newRoom;
    Customer newCustomer;
    Booking newBooking( 5, newRoom, newCustomer, Date(), false );
    BOOST_CHECK_EQUAL( newBooking.getID(), 2 );
    BOOST_CHECK_EQUAL( newBooking.getDays(), 5 );
    BOOST_CHECK_EQUAL( &newBooking.getRoom() == &newRoom, true );
    BOOST_CHECK_EQUAL( &newBooking.getCustomer() == &newCustomer, true );
    Date date1;
    BOOST_CHECK_EQUAL( newBooking.getDateStart().getDay(), date1.getDay() );
    BOOST_CHECK_EQUAL( newBooking.getDateStart().getMonth(), date1.getMonth() );
    BOOST_CHECK_EQUAL( newBooking.getDateStart().getYear(), date1.getYear() );
    Date date2 = date1 + 4;
    BOOST_CHECK_EQUAL( newBooking.getDateEnd().getDay(), date2.getDay() );
    BOOST_CHECK_EQUAL( newBooking.getDateEnd().getMonth(), date2.getMonth() );
    BOOST_CHECK_EQUAL( newBooking.getDateEnd().getYear(), date2.getYear() );
    BOOST_CHECK_EQUAL( newBooking.getState(), false );
}

BOOST_AUTO_TEST_SUITE_END()

