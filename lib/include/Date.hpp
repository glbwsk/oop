#ifndef DATE_HPP
#define DATE_HPP

class Date
{
public:
    Date();
    Date( int day, int month, int year );
    virtual ~Date() = default;

    void setCurrent();

    // getters & setters
    int getDay();
    int getMonth();
    int getYear();

    void setDay( int day );
    void setMonth( int month );
    void setYear( int year );

    Date operator + ( const int& days );
    bool operator > ( const Date& date );
    bool operator < ( const Date& date );

protected:

private:
    int day;
    int month;
    int year;
};

#endif // DATE_HPP
