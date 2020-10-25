#include "Worker.h"
#include <stdexcept>

Worker::Worker(const long &id, const string &name, const string &surname, const Date &birthday, const string &type,
               double salary, const string &mobileNumber) : Person(id, name, surname, birthday), type(type),
                                                            salary(salary), mobileNumber(mobileNumber) {checkSalary();}

const string &Worker::getType() const {
    return type;
}

void Worker::setType(const string &type) {
    this->type = type;
}

double Worker::getSalary() const {
    return salary;
}

void Worker::setSalary(double salary) {
    this->salary = salary;
    checkSalary();
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
    checkSalary();
    this->mobileNumber = parameters->at(2);
    parameters->erase(parameters->begin(),parameters->cbegin()+3);
};

void Worker::checkSalary() const{
    if (this->salary<0) throw std::invalid_argument("Salary can't be lower then 0");
}

Worker::Worker():Person() {}
