#ifndef CLEANER_HPP
#define CLEANER_HPP

#include "Employee.hpp"
#include "Room.hpp"
#include "Floor.hpp"

#include <vector>
#include <memory>

class Cleaner : public Employee
{
public:
    Cleaner( Employee employee );
    virtual ~Cleaner() = default;

    void cleanRoom( Room &room );
    void cleanFloor( Floor &floor );

protected:

private:
};

#endif // CLEANER_HPP
