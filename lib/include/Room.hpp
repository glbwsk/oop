#ifndef ROOM_HPP
#define ROOM_HPP

#include "Date.hpp"
#include "Equipment.hpp"

#include <vector>
#include <memory>

class Room
{
public:
    Room( int number = 0,
          int floorNumber = 0,
          int pricePerDay = 100 );
    virtual ~Room() = default;

    // getters & setters
    int getNumber();
    void setNumber( int val );
    int getPricePerDay();
    void setPricePerDay( int val );
    Date getDateCleaned();
    void setDateCleaned( Date val );
    std::vector<std::shared_ptr<Equipment>>& getEquipment();
    void setFloorNumber( int floorNumber );
    int getFloorNumber();

protected:

private:
    int number;
    int pricePerDay;
    Date dateCleaned;
    std::vector<std::shared_ptr<Equipment>> equipment;
    int floorNumber;

};

#endif // ROOM_HPP
