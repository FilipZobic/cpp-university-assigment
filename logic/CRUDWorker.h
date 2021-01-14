#ifndef CPP_UNIVERSITY_ASSIGMENT_CRUDWORKER_H
#define CPP_UNIVERSITY_ASSIGMENT_CRUDWORKER_H

#include <model/Department.h>
#include "string"
#include "CRUD.h"
#include "../service/WorkerService.h"
#include "../service/DepartmentMultiService.h"
using namespace std;

class CRUDWorker : public CRUD<Worker*> {
private:
    Department *department;
    DepartmentMultiService * const departmentService;
public:
    CRUDWorker(WorkerService *service, DepartmentMultiService *departmentService);//Worker service

    void removeEntity(const long id) override;

    void replaceEntity(Worker *newWorker) override;

    void createEntity(Worker *const entity) override;

    Department *getDepartment() const;

    void setDepartment(Department *department);

    void setBoss(Worker* boss);
};

#endif