#ifndef CPP_UNIVERSITY_ASSIGMENT_CRUDDEPARTMENT_H
#define CPP_UNIVERSITY_ASSIGMENT_CRUDDEPARTMENT_H

using namespace std;

#include "CRUD.h"
#include "../model/Department.h"

class CRUDDepartment : public CRUD<Department*>  {
public:
    CRUDDepartment(Service<Department *> *service);


    void replaceEntity(vector<string> &newParams, int id, void *businessService) override;

    void removeEntity(const long id, void *service) override;

};


#endif //CPP_UNIVERSITY_ASSIGMENT_CRUDDEPARTMENT_H
