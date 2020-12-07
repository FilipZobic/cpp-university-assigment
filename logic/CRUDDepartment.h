#ifndef CPP_UNIVERSITY_ASSIGMENT_CRUDDEPARTMENT_H
#define CPP_UNIVERSITY_ASSIGMENT_CRUDDEPARTMENT_H

using namespace std;

#include <model/Business.h>
#include "CRUD.h"
#include "../model/Department.h"

class CRUDDepartment : public CRUD<Department*>  {
private:
    Business *business;
public:
    CRUDDepartment(Service<Department *> *service);


    void replaceEntity(vector<string> &newParams, int id) override;

    void removeEntity(const long id) override;

};


#endif //CPP_UNIVERSITY_ASSIGMENT_CRUDDEPARTMENT_H
