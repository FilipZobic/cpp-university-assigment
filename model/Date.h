#ifndef CPP_UNIVERSITY_ASSIGMENT_Date_H
#define CPP_UNIVERSITY_ASSIGMENT_Date_H
#include <string>
#include "../service/CsvFormatter.h"
class Date : public CsvFormatter<string&>{
    private:
        int static const days31 = 31;
        int static const days30 = 30;
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int const day,int const month,int const year);
        ~Date();

        int getDay() const;

        int getMonth() const; 

        int getYear() const;

        std::string toString() const;

        string Serialize() override;

protected:
    bool isInputValid(const int &day, const int &month, const int &year);

    int getSumOfDays();

    void Parse(string &dateString) override;
};

#endif