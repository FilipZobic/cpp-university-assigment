//
// Created by filipz on 10/24/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_WORKERSERVICE_H
#define CPP_UNIVERSITY_ASSIGMENT_WORKERSERVICE_H

#include <string>
#include <vector>
#include <iostream>
//#include <ifstream>
//#include <ofstream>

#include "../model/Worker.h"

using namespace std;

class WorkerService {
public:
    void ParseWorker(string workerString,Worker *worker);
    void ParseVectorWorkers(vector<Worker*> *workersVector);


};

#endif //CPP_UNIVERSITY_ASSIGMENT_WORKERSERVICE_H
