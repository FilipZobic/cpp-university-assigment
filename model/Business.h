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

    string address;
    string phoneNumber;
public:
    Business();

    Business(const string &name, long registrationNumber, long vat, string phoneNumber,string address);

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

    vector<Department*>* getDepartmentsConst();

    vector<long> departmentIds();

    int getNumberOfSpecificWorker(Department::Type type);

    double calculateSpending() const;

    const string &getAddress() const;

    void setAddress(const string &address);

    const string &getPhoneNumber() const;

    void setPhoneNumber(const string &phoneNumber);
};


#endif //CPP_UNIVERSITY_ASSIGMENT_BUSINESS_H
