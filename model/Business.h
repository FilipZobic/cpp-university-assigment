//
// Created by filipz on 12/5/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESS_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESS_H

#include <string>
#include <vector>
#include "Department.h"
#include "service/CsvFormatter.h"

using namespace std;
// Implements formatter // Add service // Add CRUD
class Business : public CsvFormatter<vector<string>*> {
private:
    string name;
    long registrationNumber;
    long vat;
    long programId;
    vector<struct Department *> *departments;
public:
    Business();
    /*
     * Worker can't exist without department tied to one
     * Department can't exist without business tied to one
     * Business can exist on its own
     *
     *
     *
     * */
    Business(const string &name, long registrationNumber, long vat);

    string Serialize() override;

    void Parse(vector<string> *parameters) override;

    void operator << (Department *department);

    const vector<Department *>* getDepartments() const;

    long getId() const;

    const string &getName() const;

    void setName(const string &name);

    void setId(long registrationNumber);

    long getVat() const;

    void setVat(long vat);

    void setDepartments(vector<struct Department *> *departments);

    long getProgramId() const;

    void setProgramId(long programId);


    vector<long> removeDepartment(const long depId);

    void replace(Business* newBusiness);

    int getNumberOfDepartments();

    int getNumberOfWorkers();
};


#endif //CPP_UNIVERSITY_ASSIGMENT_BUSINESS_H
