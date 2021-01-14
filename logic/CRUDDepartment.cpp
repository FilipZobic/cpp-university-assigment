#include "CRUDDepartment.h"




//calls the save method after finding correct department
//add fire
//add hire
CRUDDepartment::CRUDDepartment
(DepartmentMultiService *departmentMultiService, WorkerService *const workerService,BusinessMultiService *const businessMultiService):
CRUD(departmentMultiService),workerService(workerService),businessMultiService(businessMultiService){}

void CRUDDepartment::replaceEntity(Department *entity) { // just replace with setter and getters old and new
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

// working on it
void CRUDDepartment::removeEntity(const long depId) {
    if (this->business == nullptr){
        throw logic_error("Business is null");
    }
    const long departmentIndex = service->findIndex(depId);
    if (departmentIndex != -1){
        // Clears department from service and business vector
            // returns workers ids
        vector<long> workersToRemove = this->business->removeDepartment(depId); // returns all workers that belong to department and erases the array then deletes it and removes the department from business.department vector
        this->service->clearMemory(depId); // deletes it from worker service; calls clear memory

        // clears worker that belonged to department from workerService and deletes them from memory
        for(long workerId : workersToRemove){
            workerService->clearMemory(workerId);
        }

//        //Write to file
        this->businessMultiService->writeToFile();
    } else {
        cout << "No element was removed because it doesn't exist" << endl;
    }
}

// Done
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
// Done
void CRUDDepartment::setBusiness(Business *business) {
    this->business = business;
}

Business *CRUDDepartment::getBusiness() const {
    return business;
}

vector<Business *> *CRUDDepartment::getBusinessServiceVector() {
    return this->businessMultiService->getEntities();
}