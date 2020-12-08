#ifndef CPP_UNIVERSITY_ASSIGMENT_WORKERSERVICE_H
#define CPP_UNIVERSITY_ASSIGMENT_WORKERSERVICE_H

#include <string>
#include <vector>
#include <iostream>

#include "../model/Worker.h"

#include "./Service.h"
#include "../model/Driver.h"
#include "../model/Warehouseman.h"
#include "../model/Clerk.h"

using namespace std;

class WorkerService : public Service<Worker*> {
public:
    WorkerService(const string &filename, vector<Worker*> *entities);

    void parseAllEntities() override;

    void parseEntity(Worker **entity, vector<string> &paramsForObject) override;

private:

};

#endif //CPP_UNIVERSITY_ASSIGMENT_WORKERSERVICE_H
