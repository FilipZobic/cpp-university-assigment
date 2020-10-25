#ifndef CPP_UNIVERSITY_ASSIGMENT_WAREHOUSEMAN_H
#define CPP_UNIVERSITY_ASSIGMENT_WAREHOUSEMAN_H

#include "Worker.h"

class Warehouseman : public Worker  {
public:
    Warehouseman();

    Warehouseman(const long &id, const string &name, const string &surname, const Date &birthday,
                 double salary, const string &mobileNumber);

    string Serialize() override;

    void Parse(vector<string> *parameters) override;
};


#endif //CPP_UNIVERSITY_ASSIGMENT_WAREHOUSEMAN_H
