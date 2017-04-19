#include <boost/test/unit_test.hpp>
#include "Address.hpp"

/* Unit tests for Adress.hpp */

/* correct */
BOOST_AUTO_TEST_SUITE( AddressSuiteCorrect )

BOOST_AUTO_TEST_CASE( ctor_default )
{
    Address newAddress1;
    BOOST_CHECK_EQUAL( newAddress1.getStreet(), "null" );
    BOOST_CHECK_EQUAL( newAddress1.getCity(), "null" );
    BOOST_CHECK_EQUAL( newAddress1.getPostalCode(), "null" );
    BOOST_CHECK_EQUAL( newAddress1.getApartmentNum(), 0 );
}

BOOST_AUTO_TEST_CASE( ctor )
{
    Address newAdress1( "ulica", "miasto", "11-235", 5 );
    BOOST_CHECK_EQUAL( newAdress1.getStreet(), "ulica" );
    BOOST_CHECK_EQUAL( newAdress1.getCity(), "miasto" );
    BOOST_CHECK_EQUAL( newAdress1.getPostalCode(), "11-235" );
    BOOST_CHECK_EQUAL( newAdress1.getApartmentNum(), 5 );
}

BOOST_AUTO_TEST_SUITE_END()

