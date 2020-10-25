//
// Created by filipz on 10/25/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_CLERK_H
#define CPP_UNIVERSITY_ASSIGMENT_CLERK_H

#include "Worker.h"
class Clerk : public Worker {
private:
    string cashRegisterInfo;
public:
    Clerk();

    Clerk(const long &id, const string &name, const string &surname, const Date &birthday,
          double salary, const string &mobileNumber, const string &cashRegisterInfo);

    string Serialize() override;

    void Parse(vector<string> *parameters) override;
};


#endif //CPP_UNIVERSITY_ASSIGMENT_CLERK_H
