#ifndef CPP_UNIVERSITY_ASSIGMENT_DRIVER_H
#define CPP_UNIVERSITY_ASSIGMENT_DRIVER_H
#include "Worker.h"

class Driver : public Worker{
private:
    vector<string> drivingCategories;
    int numTrafficInfractions;
public:
    void addDrivingCategory(string category); // ili na zaukrozivanje ponudjeno ne prikazuje ako vec ima
    Driver();

    Driver(const long &id, const string &name, const string &surname, const Date &birthday,
           double salary, const string &mobileNumber, const int &numTrafficInfractions,vector<string> &cat);

    Driver(const long &id, const string &name, const string &surname, const Date &birthday,
           double salary, const string &mobileNumber, int numTrafficInfractions);

    string Serialize() override;

    void Parse(vector<string> *parameters) override;

    int getNumTrafficInfractions() const;

    void setNumTrafficInfractions(int numTrafficInfractions);

    string drivingCategoriesToString();
};


#endif //CPP_UNIVERSITY_ASSIGMENT_DRIVER_H
