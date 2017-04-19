#include <boost/test/unit_test.hpp>
#include "Bed.hpp"

/* Unit tests for Bed.hpp */

/* correct */
BOOST_AUTO_TEST_SUITE( BedSuiteCorrect )

BOOST_AUTO_TEST_CASE( ctor )
{
    Bed newBed( 5, "typ lozka" );
    BOOST_CHECK_EQUAL( newBed.getCapacity(), 5 );
    BOOST_CHECK_EQUAL( newBed.getType(), "typ lozka" );
}

BOOST_AUTO_TEST_SUITE_END()

