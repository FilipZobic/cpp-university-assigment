#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESSMULTISERVICE_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESSMULTISERVICE_H


#include <model/Business.h>
#include "MultiService.h"
#include "DepartmentService.h"

class BusinessMultiService : public MultiService<Business*,DepartmentService*> {
public:
    BusinessMultiService(const string &filename, vector<Business*> *entities, DepartmentService *serviceDependency);

    void parseAllEntities() override;

    void parseEntity(Business **entity, vector<string> &paramsForObject) override;
};


#endif //CPP_UNIVERSITY_ASSIGMENT_BUSINESSMULTISERVICE_H
