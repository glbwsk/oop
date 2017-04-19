#include "Floor.hpp"

Floor::Floor( int number ) :
    number( number ),
    dateCleaned( Date( 0, 0, 0 ) )
{

}

void Floor::addRoom ( Room room )
{
    this->rooms.push_back( room );
}

int Floor::getNumber()
{
    return number;
}

void Floor::setNumber( int val )
{
    number = val;
}

Date Floor::getDateCleaned()
{
    return dateCleaned;
}

void Floor::setDateCleaned( Date val )
{
    dateCleaned = val;
}

std::vector<Room>& Floor::getRooms()
{
    return rooms;
}


