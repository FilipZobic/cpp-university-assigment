//
// Created by filipz on 10/24/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_WORKER_H
#define CPP_UNIVERSITY_ASSIGMENT_WORKER_H
#include "Person.h"
#include "../service/CsvFormatter.h"

#include <string>
#include <vector>

using namespace std;

class Worker : public Person,public CsvFormatter {
private:
    string type;
    double salary;
    string mobileNumber;
public:
    Worker();

    Worker(const long &id, const string &name, const string &surname, const Date &birthday, const string &type,
           double salary, const string &mobileNumber);

    const string &getType() const;

    void setType(const string &type);

    double getSalary() const;

    void setSalary(double salary);

    const string &getMobileNumber() const;

    void setMobileNumber(const string &mobileNumber);

    string Serialize() override /*pure virtual*/;

    void Parse(vector<string> *parameters) override /*pure virtual*/;
};


#endif //CPP_UNIVERSITY_ASSIGMENT_WORKER_H
