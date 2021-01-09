//
// Created by filipz on 10/26/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_DEPARTMENT_H
#define CPP_UNIVERSITY_ASSIGMENT_DEPARTMENT_H

#include "Worker.h"

class Department : public CsvFormatter<vector<string>>{
private: //add name to department then fix service then parse ser then crude Parse should recieve params id and name also other paramaters shift one position
    long id;
    string name;
    Worker* boss;
    vector<Worker*>* workers;
public:
    Department();
    Department(long id);
    Department(long id,vector<Worker *> *workers);
    Department(long id, Worker *boss,vector<Worker *> *workers);
    Department(long id, string name, Worker *boss,vector<Worker *>* workers);
    ~Department();

    void hireWorker(Worker* worker);
    void fireWorker(const long &id);
    void replaceWorker(Worker *worker);

    string Serialize() override;

    void Parse(vector<string> params) override;

    long getId() const;

    void setId(long id);

    Worker *getBoss() const;

    void setBoss(Worker *boss);

    const string &getName() const;

    void setName(const string &name);

    vector<Worker *> *getWorkers() const;

    void setWorkers(vector<Worker *> *workers);

    static const string &getSep();

    void operator << (Worker *worker);

    int getNumberOfWorkers();


};


#endif //CPP_UNIVERSITY_ASSIGMENT_DEPARTMENT_H
