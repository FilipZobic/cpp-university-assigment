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
    const long index = service->findIndex(id);
    if (index!=-1){
        this->department->fireWorker(id);

        this->deleteEntity(index);
        this->departmentService->writeToFile();
    } else {
        cout << "No element was removed because it doesn't exist" << endl;
    }
}

void CRUDWorker::replaceEntity(Worker *newWorker) {
    if (this->department == nullptr){
        throw logic_error("Department is null");
    }
    const long index = service->findIndex(newWorker->getId());
    if (index!=-1){
        this->department->replaceWorker(newWorker);
        this->replace(index,newWorker);
    } else {
        cout << "No element will be replaced because it doesn't exist" << endl;
    }
}

void CRUDWorker::createEntity(Worker *const worker) {
    worker->setId(service->getLastUsedId());
    this->addEntity(worker);
    this->department->hireWorker(worker);
    this->departmentService->writeToFile();
}

Department *CRUDWorker::getDepartment() const {
    return department;
}

void CRUDWorker::setDepartment(Department *department) {
    CRUDWorker::department = department;
}

