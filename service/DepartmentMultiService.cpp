#include "DepartmentMultiService.h"

#include "../util/Util.h"

#include <bits/stdc++.h>

DepartmentMultiService::DepartmentMultiService(const string &filename, vector<Department*> *entities, WorkerService *serviceDependency) : MultiService(filename, entities,serviceDependency){
    parseAllEntities();
}
void DepartmentMultiService::parseAllEntities() {
    vector<string> lines = readFromFile();
    unordered_set <long> idSet;
    for (string &line : lines) {
        vector<string> paramsForObject;
        cuaUtil::parseStringIntoVector(line,paramsForObject,"|*|"); //Business Service

        string workerIdsString = paramsForObject.at(3);
        paramsForObject.erase(paramsForObject.begin()+3);
        vector<string> workerIds;

        long bossId = stol(paramsForObject.at(2));
        paramsForObject.erase(paramsForObject.begin()+2);

        cuaUtil::parseStringIntoVector(workerIdsString,workerIds,",");

        Department* entity;
        this->parseEntity(&entity,paramsForObject);


        for (string i : workerIds){
            int id = stoi(i);
            if (idSet.find(id) != idSet.end()) {
                throw logic_error("Worker with that id was already stored in a department"); // can be template
            }
            for (Worker* worker : *this->serviceDependency->getEntities()) {
                if (id == worker->getId()){
                    idSet.insert(id);
                    *entity << worker;
                    if (id == bossId){
                        entity->setBoss(worker);
                    }
                    break;
                }
            }
        }
        entities->push_back(entity);
    }
    if (serviceDependency->getEntities()->size() != idSet.size()){
        throw logic_error("There are workers that exist without a Department"); // can be template
    }
}

void DepartmentMultiService::parseEntity(Department **entity, vector<string> &paramsForObject) {

    (*entity) = new Department;
    (*entity)->Parse(paramsForObject);
}

