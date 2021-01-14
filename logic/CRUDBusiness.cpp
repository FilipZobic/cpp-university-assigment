#include "CRUDBusiness.h"

CRUDBusiness::CRUDBusiness(Service<Business *> *service, CRUDDepartment *crudDepartment) :
        CRUD(service),crudDepartment(crudDepartment) {
    for (Business* business : *this->service->getEntities()){
        this->businessIdHashSet[business->getId()] = business;
    }
}

void CRUDBusiness::createEntity(Business *const business) {
    if (this->businessIdHashSet.find(business->getId()) != this->businessIdHashSet.end()){
        throw logic_error ("A business already has that registration number");
    }

    business->setProgramId(service->getLastUsedId());

    this->businessIdHashSet[business->getId()] = business;
    this->addEntity(business);
    this->service->writeToFile();
}

void CRUDBusiness::replaceEntity(Business *newBusiness) {

    bool canReplace = false;
    Business *oldBusiness;

    for (auto &map : this->businessIdHashSet) {
        canReplace = map.second->getProgramId() == newBusiness->getProgramId();
        oldBusiness = map.second;
        cout << "Can replace: " << canReplace << endl;
        if(canReplace) break;
    }

    if(!canReplace) throw logic_error ("Nothing to replace");

    auto index = this->businessIdHashSet.find(newBusiness->getId());

    if (index != this->businessIdHashSet.end()){
        if (oldBusiness != this->businessIdHashSet.find(newBusiness->getId())->second){
            throw logic_error ("A business already has that registration number");
        }
    }
    this->businessIdHashSet.erase(businessIdHashSet.find(oldBusiness->getId()));
    oldBusiness->replace(newBusiness);
    this->businessIdHashSet[oldBusiness->getId()] = oldBusiness;
    delete newBusiness;
    this->service->writeToFile();
}

void CRUDBusiness::removeEntity(const long id) {
    long registrationNumber = id;

    if (!this->businessIdHashSet.count(id)) {
        throw logic_error("Nothing to remove");
    }

    auto index = this->businessIdHashSet.find(id);

    Business *business = index->second;
    crudDepartment->setBusiness(business);
    vector<long> ids = business->departmentIds();
    for (long id : ids) {
        crudDepartment->removeEntity(id);
    }

    this->businessIdHashSet.erase(businessIdHashSet.find(registrationNumber));

    const long businessIndex = service->findIndex(registrationNumber);

    if (businessIndex == -1) throw logic_error("ERROR Business is not valid");

    this->service->clearMemory(registrationNumber);
}