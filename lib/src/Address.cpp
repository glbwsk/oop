#include "Address.hpp"

Address::Address( std::string street, std::string city, std::string postalCode, int apartmentNum )
{
    this->street = street;
    this->city = city;
    this->postalCode = postalCode;
    this->apartmentNum = apartmentNum;
}

void Address::setStreet( std::string street )
{
    this->street = street;
}

void Address::setCity( std::string city )
{
    this->city = city;
}

void Address::setPostalCode( std::string postalCode )
{
    this->postalCode = postalCode;
}

void Address::setApartmentNum( int apartmentNum )
{
    this->apartmentNum = apartmentNum;
}

std::string Address::getStreet()
{
    return street;
}

std::string Address::getCity()
{
    return city;
}

std::string Address::getPostalCode()
{
    return postalCode;
}

int Address::getApartmentNum()
{
    return apartmentNum;
}

