//
// Created by filipz on 10/25/20.
//

#include "Driver.h"
#include "../util/Util.h"
Driver::Driver():Worker() {}

Driver::Driver(const long &id, const string &name, const string &surname, const Date &birthday,
               double salary, const string &mobileNumber, const int &numTrafficInfractions,vector<string> &cat)
               : Worker(id, name, surname, birthday, "Driver", salary, mobileNumber),drivingCategories(cat),
                                            numTrafficInfractions(numTrafficInfractions) {};

string Driver::Serialize() {
    string categories = "";
    if (!drivingCategories.empty()){
        for (string &ref : drivingCategories) {
            categories += ref + ",";
        }
        categories.erase(categories.size()-1,categories.size());
    } else{
        categories += ""; //check if empty when parsing the first vector can remove this but let it be here for now
    }
    return Worker::Serialize() + sep + categories + sep + to_string(numTrafficInfractions);
}

void Driver::Parse(vector<string> *parameters) {
    Worker::Parse(parameters);
    vector<string> categories;
    cuaUtil::parseStringIntoVector(parameters->at(0),categories,",");
    this->drivingCategories = categories;
    this->numTrafficInfractions = stoi(parameters->at(1));
}
