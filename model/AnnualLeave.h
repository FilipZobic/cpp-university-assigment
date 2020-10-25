#ifndef CPP_UNIVERSITY_ASSIGMENT_ANNUALLEAVE_H
#define CPP_UNIVERSITY_ASSIGMENT_ANNUALLEAVE_H


using namespace std;
#include "Date.h"
#include "../service/CsvFormatter.h"

class AnnualLeave : CsvFormatter<string&> {
private:
    static const int maxPossible = 24;
    int currentAmount = 0;
    Date start;
    Date end;
public:
    /*
     * start must be higher then end
     * when setting values always call datesValidation
     * current amount will always be set to 0
     * when serialization check if 0 then just write 0 as value
     * when parsing check if 0 then just set current amount
     * when serialization if not just 0 then write dates also
     * when parsing if not just 0 then parse and set dates as well
     * minimum year is 2010
     * on calculate days send year of firstParamForBoth
     * */

    void datesValidation(Date &start,Date &end,int &currentAmount);

private:
    string Serialize() override;

    void Parse(string &parameters) override;

};


#endif //CPP_UNIVERSITY_ASSIGMENT_ANNUALLEAVE_H
