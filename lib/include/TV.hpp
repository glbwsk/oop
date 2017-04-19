#ifndef TV_HPP
#define TV_HPP

#include "Equipment.hpp"

#include <string>

class TV : public Equipment
{
public:
    TV( int size = 1, std::string type = "unknown" );
    virtual ~TV() = default;

    // getters & setters
    int getSize();
    void setSize( int val );
    std::string getType();
    void setType( std::string val );

    virtual void print( IHotel *iHotel ) override;

    virtual void read( IHotel *iHotel ) override;

protected:

private:
    int size;
    std::string type;
};

#endif // TV_HPP
