//
// Created by filipz on 12/5/20.
//

#include "Business.h"
#include "../util/Util.h"

Business::Business():departments(new vector<struct Department *>) {}

Business::Business(const string &name, long registrationNumber, long vat, string phoneNumber, string address)
        : name(name), registrationNumber(registrationNumber), vat(vat),departments(new vector<struct Department *>)
                ,phoneNumber(phoneNumber),address(address){}

void Business::operator<<(Department *department) {

    cuaUtil::vectorInstanceCheck<Department>(department,this->departments);

    this->departments->push_back(department);
}

string Business::Serialize() {

    string departmentsString = "";
    if (!departments->empty()){
        for (Department *ref : *departments) {
            departmentsString += to_string(ref->getId()) + ",";
        }
        departmentsString.erase(departmentsString.size()-1,departmentsString.size());
    } else{
        departmentsString += "-1";
    }

    return this->name + sep + to_string(this->registrationNumber) + sep + to_string(this->vat)
    + sep + departmentsString + sep + to_string(programId) + sep + this->phoneNumber + sep + address;
}

void Business::Parse(vector<string> *parameters) {
    this->name = parameters->at(0);
    this->registrationNumber = stol(parameters->at(1));
    this->vat = stol(parameters->at(2));
    this->programId = stol(parameters->at(3));
    this->phoneNumber = parameters->at(4);
    this->address = parameters->at(5);
}

vector<long> Business::removeDepartment(const long depId) {
    vector<long> workerIds;

    long index = cuaUtil::findIndex<Department*>(depId, this->departments);
    if (index != -1){
        Department *department = this->departments->at(index);
        for(Worker* worker : *department->getWorkers()){
            workerIds.push_back(worker->getId());
        }
        this->departments->erase(this->departments->begin() + index);
    }else {
        throw logic_error ("There is no department with that id in this business");
    }

    return workerIds;
}

void Business::replace(Business *newBusiness) {
    this->name = newBusiness->getName();
    this->registrationNumber = newBusiness->getId();
    this->vat = newBusiness->getVat();
    this->address = newBusiness->getAddress();
    this->phoneNumber = newBusiness->getPhoneNumber();
}

const vector<Department *>* Business::getDepartments() const { // pogeldaj gde se koristi
    return departments;
}

long Business::getId() const {
    return registrationNumber;
}

void Business::setId(long registrationNumber) {
    this->registrationNumber = registrationNumber;
}

const string &Business::getName() const {
    return name;
}

void Business::setName(const string &name) {
    this->name = name;
}

long Business::getVat() const {
    return vat;
}

void Business::setVat(long vat) {
    this->vat = vat;
}

void Business::setDepartments(vector<struct Department *> *departments) {
    this->departments = departments;
}

long Business::getProgramId() const {
    return programId;
}

void Business::setProgramId(long programId) {
    this->programId = programId;
}

int Business::getNumberOfDepartments() {
    return this->departments->size();
}

int Business::getNumberOfWorkers() {
    int sum = 0;
    for(Department *department : *this->departments){
        sum += department->getNumberOfWorkers();
    }
    return sum;
}

vector<Department *> *Business::getDepartmentsConst() {
    return this->departments;
}

vector<long> Business::departmentIds() {
    vector<long> ids;

    for(Department *department : *this->departments){
        ids.push_back(department->getId());
    }

    return ids;
}

int Business::getNumberOfSpecificWorker(Department::Type type) {
    int sum = 0;
    for (Department *dep : *departments) {
        sum += dep->getNumberOfSpecificWorker(type);
    }
    return sum;
}

double Business::calculateSpending() const {
    double sum = 0;
    for (Department *department : *this->departments) {
        sum += department->getSpending();
    }
    return sum;
}

const string &Business::getAddress() const {
    return address;
}

void Business::setAddress(const string &address) {
    Business::address = address;
}

const string &Business::getPhoneNumber() const {
    return phoneNumber;
}

void Business::setPhoneNumber(const string &phoneNumber) {
    Business::phoneNumber = phoneNumber;
}
