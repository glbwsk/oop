#include "TV.hpp"
#include "IHotel.hpp"

TV::TV( int size, std::string type ) :
    size( size ),
    type( type )
{

    setClassID( 1 );
}


void TV::print( IHotel* iHotel )
{
    iHotel->printTV( *this );
}

void TV::read( IHotel* iHotel )
{
    iHotel->readTvData( this );
}

int TV::getSize()
{
    return size;
}

void TV::setSize( int val )
{
    this->size = val;
}

std::string TV::getType()
{
    return type;
}

void TV::setType( std::string val )
{
    this->type = val;
}

