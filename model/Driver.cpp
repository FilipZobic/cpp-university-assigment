#include "Driver.h"
#include "../util/Util.h"
Driver::Driver():Worker() {}

Driver::Driver(const long &id, const string &name, const string &surname, const Date &birthday,
               double salary, const string &mobileNumber, const int &numTrafficInfractions,vector<string> &cat)
               : Worker(id, name, surname, birthday, "Driver", salary, mobileNumber),drivingCategories(cat),
                                            numTrafficInfractions(numTrafficInfractions) {};

string Driver::Serialize() {
    return Worker::Serialize() + sep + drivingCategoriesToString() + sep + to_string(numTrafficInfractions);
}

void Driver::Parse(vector<string> *parameters) {
    Worker::Parse(parameters);
    vector<string> categories;
    cuaUtil::parseStringIntoVector(parameters->at(0),categories,",");
    this->drivingCategories = categories;
    this->numTrafficInfractions = stoi(parameters->at(1));
}

int Driver::getNumTrafficInfractions() const {
    return numTrafficInfractions;
}

void Driver::setNumTrafficInfractions(int numTrafficInfractions) {
    Driver::numTrafficInfractions = numTrafficInfractions;
}

Driver::Driver(const long &id, const string &name, const string &surname, const Date &birthday,
               double salary, const string &mobileNumber, int numTrafficInfractions) : Worker(id, name, surname,
                                                                                              birthday, "Driver", salary,
                                                                                              mobileNumber),
                                                                                       numTrafficInfractions(
                                                                                               numTrafficInfractions) {}

void Driver::addDrivingCategory(string category) {
    this->drivingCategories.push_back(category);
}

string Driver::drivingCategoriesToString() {
    string categories = "";
    if (!drivingCategories.empty()){
        for (string &ref : drivingCategories) {
            categories += ref + ",";
        }
        categories.erase(categories.size()-1,categories.size());
    } else{
        categories += "";
    }
    return categories;
}
