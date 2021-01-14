#ifndef CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTMULTISERVICE_H
#define CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTMULTISERVICE_H

#include <string>
#include <vector>
#include <fstream>



#include "./MultiService.h"
#include "../model/Department.h"
#include "WorkerService.h"

class DepartmentMultiService : public MultiService<Department*,WorkerService*>{
public:
    DepartmentMultiService(const string &filename, vector<Department*> *entities, WorkerService *serviceDependency);

    void parseAllEntities() override;

    void parseEntity(Department **entity, vector<string> &paramsForObject) override;
};


#endif
