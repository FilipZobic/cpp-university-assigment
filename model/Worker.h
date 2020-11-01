#ifndef CPP_UNIVERSITY_ASSIGMENT_WORKER_H
#define CPP_UNIVERSITY_ASSIGMENT_WORKER_H
#include "Person.h"
#include "../service/CsvFormatter.h"

#include <string>
#include <vector>
#include "AnnualLeave.h"
#include "fstream"

using namespace std;

class Worker : public Person,public CsvFormatter<vector<string>*> {
private:
    string type;
    double salary;
    string mobileNumber;
    AnnualLeave *annualLeave;
public:
    Worker();

    Worker(const long &id, const string &name, const string &surname, const Date &birthday, const string type,
           double salary, const string &mobileNumber);

    virtual ~Worker();

    const string &getType() const;

    void setType(const string &type);

    double getSalary() const;

    void setSalary(double salary);

    const string &getMobileNumber() const;

    void setMobileNumber(const string &mobileNumber);

    virtual string Serialize() override = 0 /*pure virtual*/;

    virtual void Parse(vector<string> *parameters) override = 0/*pure virtual*/;

    void checkSalary() const;

    void addOrReplaceAnnualLeave(Date &dateStart,Date &dateEnd) const;
};


#endif //CPP_UNIVERSITY_ASSIGMENT_WORKER_H
