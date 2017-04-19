#include <boost/test/unit_test.hpp>
#include "Bill.hpp"
#include "Room.hpp"
#include "Customer.hpp"
#include "Date.hpp"

/* Unit tests for Bill.hpp */

/* correct */
BOOST_AUTO_TEST_SUITE( BillSuiteCorrect )

BOOST_AUTO_TEST_CASE( ctor_setter )
{
    Room newRoom;
    Customer newCustomer;
    Booking newBooking( 5, newRoom, newCustomer, Date() );
    Bill newBill( &newBooking );
    BOOST_CHECK_EQUAL( newBill.getAmount(), 500 );
    BOOST_CHECK_EQUAL( newBill.getBookingPtr() == nullptr, true );
    newBill.setBookingPtr( &newBooking );
    BOOST_CHECK_EQUAL( newBill.getBookingPtr() == &newBooking, true );
}

BOOST_AUTO_TEST_SUITE_END()

