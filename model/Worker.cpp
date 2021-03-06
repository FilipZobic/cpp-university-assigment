#include "Worker.h"
#include <stdexcept>

Worker::Worker(const long &id, const string &name, const string &surname, const Date &birthday, const string type,
               double salary, const string &mobileNumber) : Person(id, name, surname, birthday), type(type),
                                                            salary(salary), mobileNumber(mobileNumber)
                                                            {
                                                                checkSalary();
                                                                this->annualLeave = new AnnualLeave();
                                                                this->annualLeave->setCurrentDays(0);
                                                            };
Worker::~Worker() {
    delete annualLeave;
}

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
    return Person::Serialize() + sep + type + sep + to_string(salary) + sep + mobileNumber + sep + annualLeave->Serialize();
}

void Worker::Parse(vector<string> *parameters) {
    Person::Parse(parameters);
    this->type = parameters->at(0);
    this->salary = stod(parameters->at(1));
    checkSalary();
    this->mobileNumber = parameters->at(2);
    this->annualLeave = new AnnualLeave();
    annualLeave->Parse(parameters->at(3));
    parameters->erase(parameters->begin(),parameters->cbegin()+4);
};

void Worker::checkSalary() const{
    if (this->salary<0) throw std::invalid_argument("Salary can't be lower then 0");
}

Worker::Worker():Person() {}

AnnualLeave *Worker::getAnnualLeave() const {
    return annualLeave;
}

void Worker::setAnnualLeave(AnnualLeave *annualLeave) {
    delete this->annualLeave;
    this->annualLeave = annualLeave;
}

string Worker::getAnnualLeaveValue(AnnualLeave::LeaveDetails leaveDetails) {
    if (annualLeave == nullptr || annualLeave->getCurrentDays() == 0){
        return "";
    }

    if (leaveDetails == AnnualLeave::Start){
        return this->annualLeave->getStart().toString();
    }else{
        return  this->annualLeave->getAnEnd().toString();
    }
};

void Worker::copyAnnualLeave(AnnualLeave *annualLeave) {
    this->annualLeave = new AnnualLeave(annualLeave);
}


