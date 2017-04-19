#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Employee.hpp"
#include "Date.hpp"

#include <vector>

class Manager : public Employee
{
public:
    Manager( Employee employee );
    virtual ~Manager() = default;

    template <class EmployeeT>
    void hire( Employee e, std::vector<EmployeeT> &empVec )
    {
        EmployeeT newEmployeeT( e );
        empVec.push_back( newEmployeeT );
    }

    template <class EmployeeT>
    bool fire( std::vector<EmployeeT> &empVec, unsigned int number )
    {
        if ( number >= empVec.size() )
        {
            return false;
        }
        else if ( std::is_same<EmployeeT, Manager>::value )
        {
            EmployeeT* empPtr =  &( *( empVec.begin() + number ) );

            if ( this == dynamic_cast<Manager*>( empPtr ) )
            {
                return false;
            }
            else
            {
                empVec.erase( empVec.begin() + number );
                return true;
            }

        }
        else
        {
            empVec.erase( empVec.begin() + number );
            return true;
        }
    }

protected:

private:
};

#endif // MANAGER_HPP
