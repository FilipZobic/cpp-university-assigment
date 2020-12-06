#include "CRUDWorker.h"
#include "stdexcept"
#include "../util/Util.h"
#include "../service/DepartmentMultiService.h"
CRUDWorker::CRUDWorker(Service<Worker *> *service) : CRUD(service) {}

void CRUDWorker::removeEntity(const long id,void *departmentService) { //ili crud buisnissservice
    const long index = findIndex(id);
    if (index!=-1){

        DepartmentMultiService *businessServiceParse = (DepartmentMultiService*)departmentService;
        for (Department *department : (*businessServiceParse->getEntities())) {
            department->fireWorker(id);
        }

        deleteEntity(index);
        businessServiceParse->writeToFile();
    } else {
        cout << "No element was removed because it doesn't exist" << endl;
    }
}


//sve moze abstrakt osim replace i remove //id will be unchanged in params
void CRUDWorker::replaceEntity(vector<string> &newParams, int id, void *departmentService) {
    const long index = findIndex(id);
    if (index!=-1){
        Worker* entity;
        newParams.at(0) = to_string(id);
        service->parseEntity(&entity,newParams);

        DepartmentMultiService *businessServiceParse = (DepartmentMultiService*)departmentService;//
        for (Department *department : (*businessServiceParse->getEntities())) {
            department->replaceWorker(id,entity);
        }

        this->replace(index,entity);

        service->writeToFile();
    } else {
        cout << "No element will be replaced because it doesn't exist" << endl;
    }
}