//
// Created by filipz on 10/26/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_DEPARTMENT_H
#define CPP_UNIVERSITY_ASSIGMENT_DEPARTMENT_H

#include "Worker.h"

class Department{
private:
    long id;
    Worker* boss; //parse with id then read from inited array using findIndex if -1 then don't add it
    vector<Worker*>* workers;
    static const string sep;
public:
    Department(long id, Worker *boss,vector<Worker *> *workers);

    void hireWorker(Worker* worker);
    void fireWorker(Worker* worker);

    string Serialize();



    void Parse(long &id,vector<long> &workerIds,vector<Worker*> *entities);


};


#endif //CPP_UNIVERSITY_ASSIGMENT_DEPARTMENT_H
