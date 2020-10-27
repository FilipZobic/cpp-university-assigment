//
// Created by filipz on 10/26/20.
//

#include "Department.h"

Department::Department(long id, Worker *boss,vector<Worker *>* workers) : id(id), boss(boss), workers(workers) {}

const string Department::sep = "||**||";

void Department::hireWorker(Worker *worker) {
    //check if in it first
}

void Department::fireWorker(Worker *worker) {
    //check if in it first //findWorker
}

string Department::Serialize() {


    string people = "";
    if (!workers->empty()){
        for (Worker *ref : (*workers)) { //ovde mozda pokazivac pokazivaca
            people += to_string(ref->getId()) + ",";
        }
        people.erase(people.size()-1,people.size());
    } else{
        people += "";
    }

    return sep + to_string(id) + sep + to_string(boss->getId()) + sep + people;
}


void Department::Parse(long &id,vector<long> &workerIds,vector<Worker*> *entities) {
    this->id = id;

}