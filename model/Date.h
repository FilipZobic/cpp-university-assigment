#ifndef CPP_UNIVERSITY_ASSIGMENT_Date_H
#define CPP_UNIVERSITY_ASSIGMENT_Date_H

#include <string>

class Date {
    private:
        int static const days31 = 31;
        int static const days30 = 30;
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int const day,int const month,int const year); //throw error if any number =< 0
        ~Date();

        int getDay() const;

        int getMonth() const; 

        int getYear() const;

        std::string toString() const;
};

#endif