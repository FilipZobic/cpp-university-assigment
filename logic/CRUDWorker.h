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
    Department *department; // not const //department preko setter if department == nullptrt error
    DepartmentMultiService * const departmentService;
public:
    CRUDWorker(WorkerService *service, DepartmentMultiService *departmentService);//Worker service

    void removeEntity(const long id) override;

    void replaceEntity(Worker *newWorker) override;

    void createEntity(Worker *const entity) override;

    void addAnnualLeave(const long id,string start, string end); // add logic for error

    Department *getDepartment() const;

    void setDepartment(Department *department);
};


#endif //CPP_UNIVERSITY_ASSIGMENT_CRUDWORKER_H
