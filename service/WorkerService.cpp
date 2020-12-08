#include "WorkerService.h"
#include "../util/Util.h"

// mogu staviti template za to ali svaki koji saljem ce imati tu klasu CsvFormater i onda zavisnosti od cega je formiraj klasu

WorkerService::WorkerService(const string &filename, vector<Worker*> *entities) : Service(filename, entities) {
    parseAllEntities();
}

void WorkerService::parseEntity(Worker **entity, vector<string> &paramsForObject) {
    //mozda moram obrisati startu memoriju
    if (paramsForObject.at(4) == "Driver"){
        (*entity) = new Driver();
    } else if(paramsForObject.at(4) == "Warehouseman"){
        (*entity) = new Warehouseman();
    } else if(paramsForObject.at(4) == "Clerk") {
        (*entity) = new Clerk();
    } else {
        throw std::runtime_error("Error in Worker type");
    }
    (*entity)->Parse(&paramsForObject);
}

void WorkerService::parseAllEntities() {
    vector<string> lines = readFromFile();
    for (string &line : lines) {
        vector<string> paramsForObject;
        cuaUtil::parseStringIntoVector(line,paramsForObject,"|*|"); // WORKER SERVICE

        Worker* entity;
        this->parseEntity(&entity,paramsForObject);
        entities->push_back(entity);
    }
}

