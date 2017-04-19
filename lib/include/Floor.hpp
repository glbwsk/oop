#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "Room.hpp"
#include "Date.hpp"

#include <vector>

class Floor
{
public:
    Floor( int number );
    virtual ~Floor() = default;

    void addRoom( Room room );

    // getters & setters
    int getNumber();
    void setNumber( int val );
    Date getDateCleaned();
    void setDateCleaned( Date val );
    std::vector<Room>& getRooms();

protected:

private:
    int number;
    Date dateCleaned;
    std::vector<Room> rooms;
};

#endif // FLOOR_HPP
