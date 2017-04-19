#include "Room.hpp"

Room::Room( int number, int floorNumber, int pricePerDay ) :
    number ( number ),
    pricePerDay ( pricePerDay ),
    dateCleaned ( Date( 0, 0, 0 ) ),
    floorNumber ( floorNumber )
{
}

int Room::getNumber()
{
    return number;
}

void Room::setNumber( int val )
{
    number = val;
}

int Room::getPricePerDay()
{
    return pricePerDay;
}

void Room::setPricePerDay( int val )
{
    pricePerDay = val;
}

Date Room::getDateCleaned()
{
    return dateCleaned;
}

void Room::setDateCleaned( Date val )
{
    dateCleaned = val;
}

std::vector<std::shared_ptr<Equipment>>& Room::getEquipment()
{
    return equipment;
}

void Room::setFloorNumber( int floorNumber )
{
    this->floorNumber = floorNumber;
}

int Room::getFloorNumber()
{
    return floorNumber;
}

