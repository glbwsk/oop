#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include <string>

class IHotel;

class Equipment
{
public:
    Equipment();
    virtual ~Equipment() = default;

    int getClassID();
    void setClassID( int classID );

    // getters & setters
    std::string getID();

    virtual void print( IHotel *iHotel ) = 0;
    virtual void read( IHotel *iHotel ) = 0;

protected:

private:
    std::string ID;
    int classID;

    static int autoID;
};

#endif // EQUIPMENT_HPP
