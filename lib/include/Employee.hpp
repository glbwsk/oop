#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Person.hpp"
#include "Date.hpp"

class Employee : public Person
{
public:
    Employee( Person p = Person(), int salary = 0, Date employDate = Date() );
    virtual ~Employee() = default;

    // getters & setters
    int getSalary();
    Date getEmployDate();
    void setSalary( int salary );
    void setEmployDate( const Date& date );

protected:

private:
    int salary;
    Date employDate;
};

#endif // EMPLOYEE_HPP
