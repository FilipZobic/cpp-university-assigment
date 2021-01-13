#ifndef CPP_UNIVERSITY_ASSIGMENT_ANNUALLEAVE_H
#define CPP_UNIVERSITY_ASSIGMENT_ANNUALLEAVE_H


using namespace std;
#include "Date.h"
#include "../service/CsvFormatter.h"

class AnnualLeave : CsvFormatter<string&> {
private:
    static const int maxPossible = 24;
    int currentDays = 0;
    Date start;
    Date end;
public:

    enum LeaveDetails{Start, End};
    /*
     * start must be higher then end
     * when setting values always call getSubtraction
     * current amount will always be set to 0
     * when serialization check if 0 then just write 0 as value
     * when parsing check if 0 then just set current amountW
     * when serialization if not just 0 then write dates also
     * when parsing if not just 0 then parse and set dates as well
     * minimum year is 2010
     * on calculate days send year of firstParamForBoth
     * */

    void setCurrentDays(Date &start, Date &end);

    void setCurrentDays(int currentDays);

    string Serialize() override;

    void Parse(string &parameters) override;

    const Date &getStart() const;

    void setStart(const Date &start);

    const Date &getAnEnd() const;

    void setAnEnd(const Date &anEnd);

    AnnualLeave(Date &start, Date &anEnd);

    AnnualLeave();

    int getCurrentDays() const;

    AnnualLeave(AnnualLeave *annualLeave);
};


#endif //CPP_UNIVERSITY_ASSIGMENT_ANNUALLEAVE_H
