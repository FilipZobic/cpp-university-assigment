#ifndef CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTSERVICE_H
#define CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTSERVICE_H

#include <string>
#include <vector>
#include <fstream>



#include "./Service.h"
#include "../model/Department.h"
#include "WorkerService.h"

class DepartmentService : public Service<Department*>{
private:
    WorkerService *workerService;
public:
    DepartmentService(const string &filename, vector<Department*> *entities, WorkerService *workerService);

    void parseAllEntities() override;

    void parseEntity(Department **entity, vector<string> &paramsForObject) override;
};


#endif //CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTSERVICE_H
