#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include <string>

class Address
{
public:
    Address( std::string street = "null",
             std::string city = "null",
             std::string postalCode = "null",
             int apartmentNum = 0 );

    virtual ~Address() = default;

    // getters & setters
    void setStreet( std::string street );
    void setCity( std::string city );
    void setPostalCode( std::string postalCode );
    void setApartmentNum( int apartmentNum );

    std::string getStreet();
    std::string getCity();
    std::string getPostalCode();
    int getApartmentNum();

protected:

private:
    std::string street;
    std::string city;
    std::string postalCode;
    int apartmentNum;
};

#endif // ADDRESS_HPP
