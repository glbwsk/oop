#include "Bed.hpp"
#include "IHotel.hpp"

Bed::Bed( int capacity, std::string type ) :
    capacity( capacity ),
    type( type )
{

    setClassID( 2 );
}

void Bed::print( IHotel* iHotel )
{
    iHotel->printBed( *this );
}

void Bed::read( IHotel* iHotel )
{
    iHotel->readBedData( this );
}

int Bed::getCapacity()
{
    return capacity;
}

void Bed::setCapacity( int val )
{
    this->capacity = val;
}

std::string Bed::getType()
{
    return type;
}

void Bed::setType( std::string val )
{
    this->type = val;
}
