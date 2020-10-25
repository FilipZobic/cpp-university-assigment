#include "Date.h"
#include <stdexcept>
Date::Date(){};
Date::Date(int const day,int const month,int const year){
    int daysInMonth[] = {days31,28,days31,days30,days31,days30,days31,days31,days30,days31,days30,days31};

    if (year%4 == 0)
    {
        if (year%100 == 0)
        {
           if (year%400 == 0)
           {
               daysInMonth[1]++;
           }
            
        } else {
            daysInMonth[1]++;
        }
    }

    if (day<=0||month<=0||year<=0)
    {
        throw std::invalid_argument("Values can't be =< 0");
    }

    if (month>12) {
        throw std::invalid_argument("Month can have maximum value of 12");
    }

    if(daysInMonth[month-1]<day) {
        throw std::invalid_argument("Number of days in specific month too high");
    }
    
    this->day = day;
    this->month = month;
    this->year = year;
}; 
Date::~Date(){};


int Date::getDay() const {
    return day;
};

int Date::getMonth() const {
    return month;
}; 

int Date::getYear() const {
    return year;
};

std::string Date::toString() const {
    std::string toReturn = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
    return toReturn;
}
