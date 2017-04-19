#include "ExceptionCin.hpp"

char const* excin::ExceptionCin::what() const throw()
{
    return "Bad input data error!";
}


char const* excin::ExceptionCin::climsg()
{
    return "Give correct data: ";
}
