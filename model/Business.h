//
// Created by filipz on 12/5/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESS_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESS_H

#include <string>
#include <vector>
#include "Department.h"

using namespace std;

class Business {
private:
    string name;
    long registrationNumber;
    long vat;
    vector<Department*> departments;
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
    Business(const string &name, long registrationNumber, long vat, const vector<Department *> &departments);

    void operator << (Department *department);
};


#endif //CPP_UNIVERSITY_ASSIGMENT_BUSINESS_H
