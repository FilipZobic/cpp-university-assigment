//
// Created by filipz on 12/5/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESS_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESS_H

#include <string>
#include <vector>
#include "Department.h"
#include "service/CsvFormatter.h"

using namespace std;
// Implements formatter // Add service // Add CRUD
class Business : public CsvFormatter<vector<string>*> {
private:
    string name;
    long registrationNumber;
    long vat;
    vector<Department*> *departments;
public:
    Business();
    /*
     * Worker can't exist without department tied to one
     * Department can't exist without business tied to one
     * Business can exist on its own
     *
     *
     *
     * */
    Business(const string &name, long registrationNumber, long vat,vector<Department *> *departments);

    string Serialize() override;

    void Parse(vector<string> *parameters) override;

    void operator << (Department *department);
};


#endif //CPP_UNIVERSITY_ASSIGMENT_BUSINESS_H
