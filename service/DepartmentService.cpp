#include "DepartmentService.h"

#include "../util/Util.h"


DepartmentService::DepartmentService(const string &filename, vector<Department*> *entities, WorkerService *workerService) : Service(filename, entities), workerService(workerService) {
    parseAllEntities();
}

void DepartmentService::parseAllEntities() {
    vector<string> lines = readFromFile();
    for (string &line : lines) {
        vector<string> paramsForObject;
        cuaUtil::parseStringIntoVector(line,paramsForObject,"|*|"); //Business Service

        Department* entity;
        this->parseEntity(&entity,paramsForObject);
        entities->push_back(entity);
    }
}

void DepartmentService::parseEntity(Department **entity, vector<string> &paramsForObject) {

    // ovde convertujem i razvajam string parametre koji su prethodno iseceni
    // mozda moram obrisati startu memoriju
    (*entity) = new Department;
    const long id = stol(paramsForObject.at(0));
    const long bossId = stol(paramsForObject.at(1));

    vector<long> longParams;
    vector<string> stringBeforeLong;
    cuaUtil::parseStringIntoVector(paramsForObject.at(2),stringBeforeLong,",");

    for (string &longS : stringBeforeLong) {
        longParams.push_back(stol(longS));
    }
    paramsForObject.erase(paramsForObject.begin(),paramsForObject.end());
    (*entity)->Parse(id,bossId,longParams,this->workerService->getEntities());
} //replace cu mozda morati redefinisati za svaki da sa novom instancom ne presnimi ga neko samo polja da zameni jer adrese se mozda zeznu

