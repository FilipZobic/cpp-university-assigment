#include "CRUDDepartment.h"

CRUDDepartment::CRUDDepartment(DepartmentMultiService *departmentMultiService, WorkerService *const workerService,BusinessMultiService *const businessMultiService):
CRUD(departmentMultiService),workerService(workerService),businessMultiService(businessMultiService){}

void CRUDDepartment::replaceEntity(Department *entity) {
    entity->setBusiness(this->business);
    if (this->business == nullptr){
        throw logic_error("Business is null");
    }
    bool isPartOfCurrentBus = false;
    for (Department* dep: *this->business->getDepartments()){
        isPartOfCurrentBus = dep->getId() == entity->getId();
        if (isPartOfCurrentBus) break;
    }
    if (!isPartOfCurrentBus) throw logic_error("That department does not belong in current business");
    long index = service->findIndex(entity->getId());
    service->getEntities()->at(index)->setName(entity->getName());
    service->writeToFile();
}


void CRUDDepartment::removeEntity(const long depId) {
    if (this->business == nullptr){
        throw logic_error("Business is null");
    }
    const long departmentIndex = service->findIndex(depId);
    if (departmentIndex != -1){

        vector<long> workersToRemove = this->business->removeDepartment(depId);
        this->service->clearMemory(depId);

        for(long workerId : workersToRemove){
            workerService->clearMemory(workerId);
        }

        this->businessMultiService->writeToFile();
    } else {
//        cout << "No element was removed because it doesn't exist" << endl;
    }
}

void CRUDDepartment::createEntity(Department *const department) {
    department->setBusiness(this->business);
    if (this->business == nullptr){
        throw logic_error("Business is null");
    }
    department->setId(service->getLastUsedId());
    this->addEntity(department);
    *this->business << department;
    this->businessMultiService->writeToFile();
}

void CRUDDepartment::setBusiness(Business *business) {
    this->business = business;
}

Business *CRUDDepartment::getBusiness() const {
    return business;
}

vector<Business *> *CRUDDepartment::getBusinessServiceVector() {
    return this->businessMultiService->getEntities();
}