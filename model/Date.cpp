#include "Date.h"
#include <stdexcept>
#include <vector>
#include "../util/Util.h"
Date::Date(){};
Date::Date(int const day,int const month,int const year){

    // If No Errors are thrown set values
    isInputValid(day, month, year);
    
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

string Date::Serialize() {
    return toString();
}

void Date::Parse(string &dateString) {
    vector<string> params;
    cuaUtil::parseStringIntoVector(dateString,params,"/");
    int day = stoi(params[0]);
    int month = stoi(params[1]);
    int year = stoi(params[2]);

    // If No Errors are thrown set values
    isInputValid(day, month, year);

    this->day = day;
    this->month = month;
    this->year = year;
}

bool Date::isInputValid(const int &day, const int &month, const int &year) {
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

    return true; // maybe remove errors and just return true or false
}

int Date::getSumOfDays() {
//    neki brojac do 12 ili nesto slicno
    int daysSum = this->day;
    int monthsSum = this->month + (this->year * 12);
    int currentMonth = this->getMonth();

    // we use current month to get days of month current month increases after each iteration but can't excede 12 || 11
};