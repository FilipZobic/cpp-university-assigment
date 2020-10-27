//
// Created by filipz on 10/25/20.
//

#include "CRUDWorker.h"
#include "stdexcept"
#include "../util/Util.h"
#include "../service/BusinessService.h"
void CRUDWorker::createEntity(vector<string> &params){
    const long index = findIndex(stol(params.at(0)));

    if (index==-1){
        Worker* newWorker;
        params[0] = to_string(service->getLastUsedId());
        service->parseEntity(&newWorker,params);
        CRUD::addEntity(newWorker); //ovde mozda trebam adresu pointera da saljem ==========================================
    } else{
        cout << "That ID is already taken" << endl;
    }
}

CRUDWorker::CRUDWorker(Service<Worker *> *service) : CRUD(service) {}

void CRUDWorker::removeEntity(const long id,void *businessService) { //ili crud buisnissservice
    const long index = findIndex(id);
    if (index!=-1){

        BusinessService *businessServiceParse = (BusinessService*)businessService;
        for (Department *department : (*businessServiceParse->getEntities())) {
            department->fireWorker(id);
        }

        deleteEntity(index);
    } else {
        cout << "No element was removed because it doesn't exist" << endl;
    }
}



void CRUDWorker::replaceEntity(vector<string> &newParams, int id) {
    const long index = findIndex(id);
    if (index!=-1){
        newParams.at(0) = to_string(id);
        vector<Worker*> *entities = service->getEntities();
//        Worker *newWorker;
//        service->parseEntity(&newWorker,newParams);
//        delete entities->at(index);
//        (*entities->at(index)) = (*newWorker); //replace values functions then delete old one here also when deleting we have to search department service everytime
        entities->at(index)->Parse(&newParams);
        service->writeToFile();
    } else {
        cout << "No element will be replaced because it doesn't exist" << endl;
    }
}

long CRUDWorker::findIndex(long id) const {
    vector<Worker*> *entities = service->getEntities();
    long index = cuaUtil::findIndex<Worker*>(id,entities);
    return index;
};