#ifndef PERSON_HPP
#define PERSON_HPP

#include "Address.hpp"

class Person
{
public:
    Person( std::string name = "null",
            std::string surname = "null",
            std::string email = "null",
            std::string telNumber = "null",
            Address address = Address() );
    virtual ~Person() = default;

    // setters & getters
    void setName( std::string name );
    void setSurname( std::string surname );
    void setEmail( std::string email );
    void setTelNumber( std::string telNumber );
    void setAddres( const Address& address );

    std::string getName();
    std::string getSurname();
    std::string getEmail();
    std::string getTelNumber();
    Address getAddress();

protected:

private:
    std::string name;
    std::string surname;
    std::string email;
    std::string telNumber;
    Address address;
};

#endif // PERSON_HPP
