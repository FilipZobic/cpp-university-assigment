#include "Warehouseman.h"

Warehouseman::Warehouseman():Worker() {}

Warehouseman::Warehouseman(const long &id, const string &name, const string &surname, const Date &birthday,
                            double salary, const string &mobileNumber) : Worker(id, name, surname,
                           birthday, "Warehouseman",
                           salary,
                           mobileNumber) {}

string Warehouseman::Serialize() {
    return  Worker::Serialize();
}

void Warehouseman::Parse(vector<string> *parameters) {
    Worker::Parse(parameters);
};