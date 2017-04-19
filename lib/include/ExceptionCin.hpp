#ifndef EXCEPTIONCIN_HPP
#define EXCEPTIONCIN_HPP

#include <exception>

namespace excin
{

class ExceptionCin : std::exception
{
public:
    virtual char const* what() const throw() override;

    char const* climsg();

protected:

private:
};

}

#endif // EXCEPTIONCIN_H
