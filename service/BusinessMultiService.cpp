#include "BusinessMultiService.h"
#include "../util/Util.h"

void BusinessMultiService::parseAllEntities() {
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
            for (Department* dep : *this->serviceDependency->getEntities()) {
                if (id == dep->getId()){
                    *entity << dep;
                    break;
                }
            }
        }

        entities->push_back(entity); // moze operator funckija koji isto proverava instancu i dodaje ga na kraju
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
