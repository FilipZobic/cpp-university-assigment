//
// Created by filipz on 10/26/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_DEPARTMENT_H
#define CPP_UNIVERSITY_ASSIGMENT_DEPARTMENT_H

#include "Worker.h"

class Department : public CsvFormatter<long>{
private:
    long id;
    Worker* boss; //parse with id then read from inited array using findIndex if -1 then don't add it
    vector<Worker*>* workers;
public:
    Department();
    Department(long id);
    Department(long id,vector<Worker *> *workers);
    Department(long id, Worker *boss,vector<Worker *> *workers);
    ~Department();

    void hireWorker(Worker* worker);
    void fireWorker(const long &id);
    void replaceWorker(const long id,Worker *worker);

    string Serialize() override;

    void Parse(long id) override;
    void parseStaff(const long &idW,vector<Worker*> *entities,const bool boss);

    long getId() const;

    void setId(long id);

    Worker *getBoss() const;

    void setBoss(Worker *boss);

    vector<Worker *> *getWorkers() const;

    void setWorkers(vector<Worker *> *workers);

    static const string &getSep();

    void operator << (Worker *worker);
};


#endif //CPP_UNIVERSITY_ASSIGMENT_DEPARTMENT_H
