#include <assert.h>
#include "Date.h"
#define ture 1
#define false 0
Date::Date(int year,int month,int day)
{
            if(_year >= 1900 && _month > 0 && _month < 13&& _day >0 && _day < GetMonth(year,month))
            {
                this->_year = year;
                this->_month = month;
                this->_day = day;
            }
            
            
}
int Date::GetMonth(int year,int month)
{
    int arr[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month == 2 && year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    {
        ++arr[2];
    }
    return arr[month];
}
void Date::Dateshow()
{
    cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
}



Date::Date(const Date& d)
{
    _year = d._year;
    _month = d._month;
    _day = d._day;
}

Date& Date::operator=(Date d)
{
    if(*this == d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;

    }
    return *this;
}
bool Date::operator==(const Date& d)  //相等
{
    if(_year == d._year && _month == d._month && _day == d._day)
    {
        return ture;
    }
    else
    {
        return false;
    }
}
bool Date::operator!=(const Date& d)  //不相等
{
    //if(_year = d._year && _month = d._month && _day = d._day)
    //{
    //    return false;
    //}
    //else
    //{
    //    return ture;
    //}
    return !(*this == d);
}
     
bool Date::operator>(const Date& d)   //d1 > d2
{
    if(_year = d._year)
    {
        if(_month = d._month)
        {
            if(_day > d._day)
            {
                return ture;
            }
            else
            {
                return false;
            }
        }
        else if(_month > d._month)
        {
            return ture;
        }
    }
    else if(_year > d._year)
    {
        return ture;
    }
    return false;

}
bool Date::operator>=(const Date& d)  //d1 >= d2
{
    return !(*this < d);
}
bool Date::operator<(const Date& d)   //d1 < d2
{
    return !(*this == d) && !(*this > d);
}
bool Date::operator<=(const Date& d)  //d1 <= d2
{
    return !(*this > d);
}

Date Date::operator+(int day)
{
    Date tmp(*this);
    tmp += day;
    return tmp;
}
Date& Date::operator+=(int day)
{
    _day += day;
    while(_day > GetMonth(_year,_month))
    {
        _day -= GetMonth(_year,_month);
        _month += 1;
    
        if(_month >12)
        {
        _year += 1;
        _month = 1;
        }
    }
    return *this;
}
Date Date::operator-(int day)
{
    Date tmp(*this);
    tmp -= day;
    return tmp;
}
Date& Date::operator-=(int day)
{
    while(_day <= day)
    {
        _month -= 1;

    if(_month == 0)
    {
        _year -= 1;
        _month = 12;
    }
    _day += GetMonth(_year,_month);
    }
    _day -= day;
    return *this;
}
int Date::operator-(const Date& d)
{
    Date min(*this);
    Date max(d);
    int flag = 1;
    if((*this) > d)
    {
        min = d;
        max = *this;
        flag = -1;
    }
    int count = 0;
    while(min!=max)
    {
        ++count;
        min += 1;
    }
    return flag*count;
}
Date& Date::operator++()
{
    *this += 1;
    return *this;
}
Date Date::operator++(int)
{
    Date tmp(*this);
    *this += 1;
    return tmp;
}
Date& Date::operator--()
{
    *this -= 1;
    return *this;
}
Date Date::operator--(int)
{
    Date tmp(*this);
    *this -= 1;
    return tmp;
}


Date::~Date()
{
    _year = 0;
    _month = 0;
    _day = 0;
}

int main()
{
    Date d1;
    cout<<&d1<<endl;
    d1 += 3;
    cout<<&d1<<endl;
}

