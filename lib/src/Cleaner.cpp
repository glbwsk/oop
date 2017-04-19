#include "Cleaner.hpp"

Cleaner::Cleaner( Employee employee ) :
    Employee( employee )
{

}

void Cleaner::cleanRoom( Room& room )
{
    room.setDateCleaned( Date() );
}

void Cleaner::cleanFloor( Floor& floor )
{
    floor.setDateCleaned( Date() );
}
