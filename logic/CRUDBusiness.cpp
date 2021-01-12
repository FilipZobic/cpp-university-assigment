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

// Namesti da moze da se menja id i neka radi proveru da li neki drugi poseduje taj id
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

    long old_registration_number = newBusiness->getId();
    Business *registrationNumberBusiness;
    auto index = this->businessIdHashSet.find(newBusiness->getId());
    if (businessIdHashSet.count(old_registration_number)){
        registrationNumberBusiness = this->businessIdHashSet.at(index->first);
    }


    
    if (index != this->businessIdHashSet.end() && registrationNumberBusiness != oldBusiness){
        throw logic_error ("A business already has that registration number");
    }

    this->businessIdHashSet.erase(businessIdHashSet.find(oldBusiness->getId()));
    this->businessIdHashSet[oldBusiness->getId()] = oldBusiness;
    oldBusiness->replace(newBusiness);
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