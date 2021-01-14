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
