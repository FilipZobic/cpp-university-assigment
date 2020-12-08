//
// Created by filipz on 12/5/20.
//

#include "Business.h"
#include "../util/Util.h"

Business::Business():departments(new vector<struct Department *>) {}

Business::Business(const string &name, long registrationNumber, long vat)
        : name(name), registrationNumber(registrationNumber), vat(vat),departments(new vector<struct Department *>) {}

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

    return this->name + sep + to_string(this->registrationNumber) + sep + to_string(this->vat) + sep + departmentsString;
}

void Business::Parse(vector<string> *parameters) {
    this->name = parameters->at(0);
    this->registrationNumber = stol(parameters->at(1));
    this->vat = stol(parameters->at(2));

}

const vector<Department *>* Business::getDepartments() const { // pogeldaj gde se koristi
    return departments;
}

long Business::getId() const {
    return registrationNumber;
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
