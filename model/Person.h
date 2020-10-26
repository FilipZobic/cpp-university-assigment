#ifndef CPP_UNIVERSITY_ASSIGMENT_PERSON_H
#define CPP_UNIVERSITY_ASSIGMENT_PERSON_H
#include <string>
#include "Date.h"
#include "service/CsvFormatter.h"
using namespace std;

#include "../service/CsvFormatter.h"

class Person : public CsvFormatter<vector<string>*> {
private:
    long id;
    string name;
    string surname;
    Date birthday;
public:
    Person();

    Person(const long &id, const string &name, const string &surname, const Date &birthday);

    long getId() const;

    void setId(long id);

    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    const Date &getBirthday() const;

    void setBirthday(const Date &birthday);

    virtual string toString() const;

    virtual string Serialize() override = 0;

    virtual void Parse(vector<string> *parameters) override = 0;

};


#endif //CPP_UNIVERSITY_ASSIGMENT_PERSON_H
