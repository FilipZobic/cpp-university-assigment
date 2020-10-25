#include "Person.h"
#include "iostream"

Person::Person() {}

Person::Person(const long &id, const string &name, const string &surname, const Date &birthday) : id(id), name(name),
                                                                                surname(surname), birthday(birthday) {}


long Person::getId() const {
    return id;
}

void Person::setId(long id) {
    Person::id = id;
};

const string &Person::getName() const {
    return name;
}

void Person::setName(const string &name) {
    this->name = name;
}

const string &Person::getSurname() const {
    return surname;
}

void Person::setSurname(const string &surname) {
    this->surname = surname;
}

const Date &Person::getBirthday() const {
    return birthday;
}

void Person::setBirthday(const Date &birthday) {
    this->birthday = birthday;
}

string Person::toString() const {
    return to_string(id) + " " + name + " " + surname + " " + birthday.toString();
}

string Person::Serialize() {
    return to_string(id) + sep + name + sep + surname + sep + birthday.toString();
}

void Person::Parse(vector<string> *parameters) {

    this->id = stol(parameters->at(0));
    this->name = parameters->at(1);
    this->surname = parameters->at(2);
//    this->birthday = birthday.Parse(parameters->at(3))
    parameters->erase(parameters->begin(),parameters->cbegin()+4);
}



