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
    Department();
    Department(long id);
    Department(long id,vector<Worker *> *workers);
    Department(long id, Worker *boss,vector<Worker *> *workers);
    ~Department();

    void hireWorker(Worker* worker);
    void fireWorker(const long &id);

    string Serialize();

    void Parse(const long &id,const long &bossId,vector<long> &workerIds,vector<Worker*> *entities);
    void parseStaff(const long &idW,vector<Worker*> *entities,const bool boss);

    long getId() const;

    void setId(long id);

    Worker *getBoss() const;

    void setBoss(Worker *boss);

    vector<Worker *> *getWorkers() const;

    void setWorkers(vector<Worker *> *workers);

    static const string &getSep();
};


#endif //CPP_UNIVERSITY_ASSIGMENT_DEPARTMENT_H
