#include "AnnualLeave.h"
#include "../util/Util.h"
#include <stdexcept>

string AnnualLeave::Serialize() {
    string toReturn = to_string(currentDays);
    if (currentDays != 0){
        toReturn+= "|" + start.Serialize() + "|" + end.Serialize();
    }
    return toReturn;
}/*we set currentDays to 0 on construction we use setter to setter that recives 2 dates then we get calculation in parser the last value we set is days*/

void AnnualLeave::Parse(string &dateString) {
    vector<string> params;
    cuaUtil::parseStringIntoVector(dateString,params,"|");

    int currentDays = stoi(params[0]);
    if (currentDays != 0) {
        Date startDate;
        Date endDate;
        startDate.Parse(params[1]);
        endDate.Parse(params[2]);

        setCurrentDays(startDate,endDate);
    } else {
        setCurrentDays(currentDays);
    }
}

void AnnualLeave::setCurrentDays(int currentDays) {
    this->currentDays = currentDays;
}

void AnnualLeave::setCurrentDays(Date &start, Date &end) {
    long daysStart = start.getSumOfDays(start.getYear());
    long daysEnd = end.getSumOfDays(start.getYear());

    int subtraction = daysEnd - daysStart;

    if (subtraction <= 0) throw std::invalid_argument("Annual leave can't be less or equal to 0");
    if (subtraction > maxPossible) throw std::invalid_argument("Annual leave can't be more then " + to_string(maxPossible) + " days.");

    this->start = start;
    this->end = end;
    this->currentDays = subtraction;
}