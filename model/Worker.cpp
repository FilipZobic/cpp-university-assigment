//
// Created by filipz on 10/24/20.
//

#include "Worker.h"


Worker::Worker(const long &id, const string &name, const string &surname, const Date &birthday, const string &type,
               double salary, const string &mobileNumber) : Person(id, name, surname, birthday), type(type),
                                                            salary(salary), mobileNumber(mobileNumber) {}

const string &Worker::getType() const {
    return type;
}

void Worker::setType(const string &type) {
    Worker::type = type;
}

double Worker::getSalary() const {
    return salary;
}

void Worker::setSalary(double salary) {
    Worker::salary = salary;
}

const string &Worker::getMobileNumber() const {
    return mobileNumber;
}

void Worker::setMobileNumber(const string &mobileNumber) {
    Worker::mobileNumber = mobileNumber;
}

string Worker::Serialize() {
    return Person::Serialize() + sep + type + sep + to_string(salary) + sep + mobileNumber;
}

void Worker::Parse(vector<string> *parameters) {
    Person::Parse(parameters);
    this->type = parameters->at(0);
    this->salary = stod(parameters->at(1));
    this->mobileNumber = parameters->at(2);
    parameters->erase(parameters->begin(),parameters->cbegin()+3);
};


Worker::Worker():Person() {}
