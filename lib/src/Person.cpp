#include "Person.hpp"

Person::Person( std::string name,
                std::string surname,
                std::string email,
                std::string telNumber,
                Address address )
{
    this->name = name;
    this->surname = surname;
    this->email = email;
    this->telNumber = telNumber;
    this->address = address;
}

void Person::setAddres( const Address& address )
{
    this->address = address;
}

void Person::setName( std::string name )
{
    this->name = name;
}

void Person::setSurname( std::string surname )
{
    this->surname = surname;
}

void Person::setEmail( std::string email )
{
    this->email = email;
}

void Person::setTelNumber( std::string telNumber )
{
    this->telNumber = telNumber;
}

std::string Person::getName()
{
    return name;
}

std::string Person::getSurname()
{
    return surname;
}

std::string Person::getEmail()
{
    return email;
}

std::string Person::getTelNumber()
{
    return telNumber;
}

Address Person::getAddress()
{
    return address;
}

