#include "Sheets.hpp"
#include "IHotel.hpp"

Sheets::Sheets( std::string colour, std::string pattern ) :
    colour( colour ),
    pattern( pattern )
{

    setClassID( 3 );
}

void Sheets::print( IHotel* iHotel )
{
    iHotel->printSheets( *this );
}

void Sheets::read( IHotel* iHotel )
{
    iHotel->readSheetsData( this );
}


std::string Sheets::getColour()
{
    return colour;
}

void Sheets::setColour( std::string val )
{
    this->colour = val;
}

std::string Sheets::getPattern()
{
    return pattern;
}

void Sheets::setPattern( std::string val )
{
    this->pattern = val;
}
