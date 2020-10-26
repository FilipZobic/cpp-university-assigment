//
// Created by filipz on 10/25/20.
//

#include "CRUDWorker.h"
#include "stdexcept"
void CRUDWorker::createEntity(vector<string> &params){
    Worker* newWorker;
    params[0] = to_string(service->getLastUsedId());
    service->parseEntity(&newWorker,params);
    CRUD::addEntity(newWorker); //ovde mozda trebam adresu pointera da saljem ==========================================
}

CRUDWorker::CRUDWorker(Service<Worker *> *service) : CRUD(service) {}

void CRUDWorker::removeEntity(const long id) {
    const long index = findIndex(id);
    if (index!=-1){
        deleteEntity(index);
    } else {
        cout << "No element was removed because it doesn't exist" << endl;
    }
}

long CRUDWorker::findIndex(const long &id) {
    long index = -1;
    vector<Worker*> *entities = service->getEntities();
    size_t i = 0;
    for (Worker* worker : (*entities)) {
        if (worker->getId() == id){
            index = i;
            break;
        }
        i++;
    }
    return index;
}

void CRUDWorker::replaceEntity(vector<string> &newParams, int id) {
    const long index = findIndex(id);
    if (index!=-1){
        vector<Worker*> *entities = service->getEntities();
        Worker *newWorker;
        service->parseEntity(&newWorker,newParams);
        delete entities->at(index);
        entities->at(index) = newWorker;
        service->writeToFile();
    } else {
        cout << "No element will be replaced because it doesn't exist" << endl;
    }
};