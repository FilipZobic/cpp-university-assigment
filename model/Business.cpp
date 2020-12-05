//
// Created by filipz on 12/5/20.
//

#include "Business.h"

Business::Business() {}

Business::Business(const string &name, long registrationNumber, long vat, const vector<Department *> &departments)
        : name(name), registrationNumber(registrationNumber), vat(vat), departments(departments) {}

void Business::operator<<(Department *department) {
    this->departments.push_back(department);
}
