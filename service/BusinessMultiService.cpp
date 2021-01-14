#include "BusinessMultiService.h"
#include "../util/Util.h"
#include <bits/stdc++.h>

void BusinessMultiService::parseAllEntities() {
    unordered_set <long> idSet;
    vector<string> lines = readFromFile();
    for (string &line : lines) {
        vector<string> paramsForObject;
        cuaUtil::parseStringIntoVector(line,paramsForObject,"|*|");

        string departmentIdsString = paramsForObject.at(3);
        paramsForObject.erase(paramsForObject.begin()+3);
        vector<string> departmentIds;

        cuaUtil::parseStringIntoVector(departmentIdsString,departmentIds,",");

        Business* entity = new Business();
        this->parseEntity(&entity,paramsForObject);

        for (string i : departmentIds){
            int id = stoi(i);
            if (idSet.find(id) != idSet.end()) {
                throw logic_error("Department with that id was already stored in a business"); // can be template
            }
            for (Department* dep : *this->serviceDependency->getEntities()) {
                if (id == dep->getId()){
                    idSet.insert(id);
                    *entity << dep;
                    dep->setBusiness(entity);
                    break;
                }
            }
        }

        entities->push_back(entity); // moze operator funckija koji isto proverava instancu i dodaje ga na kraju
    }
    if (serviceDependency->getEntities()->size() != idSet.size()){
        throw logic_error("There are departments that exist without a Business"); // can be template
    }
}

void BusinessMultiService::parseEntity(Business **entity, vector<string> &paramsForObject) {
    (*entity)->Parse(&paramsForObject);
}

BusinessMultiService::BusinessMultiService
    (const string &filename, vector<Business*> *entities, DepartmentMultiService *serviceDependency) :
        MultiService(filename,entities,serviceDependency) {
    this->parseAllEntities();
}
