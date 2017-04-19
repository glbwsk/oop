#ifndef SHEETS_HPP
#define SHEETS_HPP

#include "Equipment.hpp"

#include <string>

class Sheets : public Equipment
{
public:
    Sheets( std::string colour = "black", std::string pattern = "unknown" );
    virtual ~Sheets() = default;

    std::string getColour();
    void setColour( std::string val );
    std::string getPattern();
    void setPattern( std::string val );

    virtual void print( IHotel *iHotel ) override;

    virtual void read( IHotel *iHotel ) override;

protected:

private:
    std::string colour;
    std::string pattern;
};

#endif // SHEETS_HPP
