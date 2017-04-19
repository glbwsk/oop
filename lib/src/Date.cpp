#include "Date.hpp"

#include <ctime>

Date::Date()
{
    setCurrent();
}

Date::Date( int day, int month, int year )
{
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::setCurrent()
{
    time_t t = time( 0 );
    struct tm * now = localtime( & t );
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

void Date::setDay( int day )
{
    this->day = day;
}

void Date::setMonth( int month )
{
    this->month = month;
}

void Date::setYear( int year )
{
    this->year = year;
}

Date Date::operator + ( const int& days )
{
    time_t t;
    struct tm * t_struct = localtime ( &t );

    t_struct->tm_year = this->year - 1900;
    t_struct->tm_mon = this->month - 1;
    t_struct->tm_mday = this->day + days;

    mktime( t_struct );

    return Date( t_struct->tm_mday, t_struct->tm_mon + 1, t_struct->tm_year + 1900 );
}

bool Date::operator > ( const Date& date )
{
    if ( this->year > date.year )
        return true;
    else if ( this->year == date.year )
        if ( this->month > date.month )
            return true;
        else if ( this->month == date.month )
            if ( this->day > date.day )
                return true;
            else
                return false;
        else
            return false;
    else
        return false;
}

bool Date::operator < ( const Date& date )
{
    if ( this->year < date.year )
        return true;
    else if ( this->year == date.year )
        if ( this->month < date.month )
            return true;
        else if ( this->month == date.month )
            if ( this->day < date.day )
                return true;
            else
                return false;
        else
            return false;
    else
        return false;
}




