#ifndef BED_HPP
#define BED_HPP

#include "Equipment.hpp"

#include <string>

class Bed : public Equipment
{
public:
    Bed( int capacity = 10, std::string type = "unknown" );
    virtual ~Bed() = default;

    int getCapacity();
    void setCapacity( int val );
    std::string getType();
    void setType( std::string val );

    virtual void print( IHotel *iHotel ) override;
    virtual void read( IHotel *iHotel ) override;

protected:

private:
    int capacity;
    std::string type;
};

#endif // BED_HPP
