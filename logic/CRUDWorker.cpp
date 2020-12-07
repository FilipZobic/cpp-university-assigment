#include "CRUDWorker.h"
#include "stdexcept"
#include "../util/Util.h"
#include "../service/DepartmentMultiService.h"
CRUDWorker::CRUDWorker(WorkerService *service, DepartmentMultiService *departmentService) :
CRUD(service), departmentService(departmentService), department(nullptr) {}

void CRUDWorker::removeEntity(const long id) {
    if (this->department == nullptr){
        throw logic_error("Department is null");
    }
    const long index = findIndex(id);
    if (index!=-1){
        this->department->fireWorker(id);
        this->deleteEntity(index);

        this->departmentService->writeToFile();
    } else {
        cout << "No element was removed because it doesn't exist" << endl;
    }
}

void CRUDWorker::replaceEntity(vector<string> &newParams, int id) {
    if (this->department == nullptr){
        throw logic_error("Department is null");
    }
    const long index = findIndex(id);
    if (index!=-1){
        Worker* entity;
        newParams.at(0) = to_string(id);
        this->service->parseEntity(&entity,newParams);

        this->department->replaceWorker(id,entity);

        this->replace(index,entity);
    } else {
        cout << "No element will be replaced because it doesn't exist" << endl;
    }
}

Department *CRUDWorker::getDepartment() const {
    return department;
}

void CRUDWorker::setDepartment(Department *department) {
    CRUDWorker::department = department;
}
