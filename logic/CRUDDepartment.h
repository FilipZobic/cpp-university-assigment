#ifndef CPP_UNIVERSITY_ASSIGMENT_CRUDDEPARTMENT_H
#define CPP_UNIVERSITY_ASSIGMENT_CRUDDEPARTMENT_H

using namespace std;

#include "CRUD.h"
#include "../model/Department.h"
#include "../util/Util.h"
#include "../service/DepartmentMultiService.h"
#include "../service/WorkerService.h"
#include "../service/BusinessMultiService.h"
#include "../model/Business.h"


//Dep Crud
//Busniss
//WorkerService
//DepartmentService
//BusinessService

class CRUDDepartment : public CRUD<Department*>  {
private:
    Business *business;
    WorkerService *const workerService;
    BusinessMultiService *const businessMultiService;
public:
    CRUDDepartment(DepartmentMultiService *departmentMultiService,
                   WorkerService *const workerService,
                   BusinessMultiService *const businessMultiService);

    void replaceEntity(Department *entity) override;

    void removeEntity(const long id) override;

    void createEntity(Department *const entity) override;

    void setBusiness(Business *business);

    Business *getBusiness() const;

    vector<Business*>* getBusinessServiceVector();
};


#endif //CPP_UNIVERSITY_ASSIGMENT_CRUDDEPARTMENT_H
