#include "Employee.hpp"

Employee::Employee( Person p, int salary, Date employDate ) :
    Person( p )
{

    this->employDate = employDate;
    this->salary = salary;
}

int Employee::getSalary()
{
    return salary;
}

Date Employee::getEmployDate()
{
    return employDate;
}

void Employee::setSalary( int salary )
{
    this->salary = salary;
}

void Employee::setEmployDate( const Date& employDate )
{
    this->employDate = employDate;
}
