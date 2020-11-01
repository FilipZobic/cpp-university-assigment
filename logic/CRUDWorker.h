#ifndef CPP_UNIVERSITY_ASSIGMENT_CRUDWORKER_H
#define CPP_UNIVERSITY_ASSIGMENT_CRUDWORKER_H
#include "string"
#include "CRUD.h"

using namespace std;


class CRUDWorker : public CRUD<Worker*> {
private:
public:
    CRUDWorker(Service<Worker *> *service);

    void removeEntity(const long id,void *departmentService = nullptr) override;

    void replaceEntity(vector<string> &newParams, int id, void *departmentService = nullptr) override;
};


#endif //CPP_UNIVERSITY_ASSIGMENT_CRUDWORKER_H
