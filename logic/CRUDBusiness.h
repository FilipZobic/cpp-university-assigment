#ifndef CPP_UNIVERSITY_ASSIGMENT_CRUDBUSINESS_H
#define CPP_UNIVERSITY_ASSIGMENT_CRUDBUSINESS_H
#include <unordered_set>
#include <unordered_map>
#include "./CRUDDepartment.h"

using namespace std;
class CRUDBusiness : public CRUD<Business*>{
private:
    unordered_map <long, Business*> businessIdHashSet;
    CRUDDepartment *crudDepartment;
    // add hasSet to check for ids
public:
    CRUDBusiness(Service<Business *> *service, CRUDDepartment *crudDepartment);

    CRUDBusiness(Service<Business *> *service, const CRUDDepartment *crudDepartment);

    void createEntity(Business *const entity) override;

    void replaceEntity(Business *newBusiness) override;

    void removeEntity(const long id) override;
private:
};

#endif //CPP_UNIVERSITY_ASSIGMENT_CRUDBUSINESS_H
