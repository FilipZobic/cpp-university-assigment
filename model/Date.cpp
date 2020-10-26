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

bool Date::isLeapYear(const int &year){
    bool toReturn = false;
    if (year%4 == 0)
    {
        if (year%100 == 0)
        {
            if (year%400 == 0)
            {
                toReturn = true;
            }

        } else {
            toReturn = true;
        }
    }
    return toReturn;
}

bool Date::isInputValid(const int &day, const int &month, const int &year) {
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (isLeapYear(year)){
        daysInMonth[1] = 29;
    }


    if (day<=0||month<=0||year<=0)
    {
        throw std::invalid_argument("Values can't be =< 0");
    }

    if (year < minYear) {
        throw std::invalid_argument("Year can't be lower then 1900");
    }

    if (month>12) {
        throw std::invalid_argument("Month can have maximum value of 12");
    }

    if(daysInMonth[month-1]<day) {
        throw std::invalid_argument("Number of days in specific month too high");
    }

    return true; // maybe remove errors and just return true or false
}

long Date::getSumOfDays(int const start) {
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    long daysSum = this->day -1;  //Its -1 because we start date can't be 0
                        //Used this for testing https://calendarhome.com/calculate/days-between-2-dates

    long daysInYear = 365;
    long daysInLeapYear = 366;

    for (int i = start; i < this->year; ++i) {
        if(isLeapYear(i)){
            daysSum += daysInLeapYear;
        }else{
            daysSum += daysInYear;
        }
    }

    if (isLeapYear(this->year)){
        daysInMonth[1] = 29;
    }

    size_t currentMonth = this->getMonth();
    for (size_t i = 0; i < currentMonth-1; ++i) {
        daysSum += daysInMonth[i];
    }

    return daysSum;
};