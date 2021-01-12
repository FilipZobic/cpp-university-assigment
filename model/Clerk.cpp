//
// Created by filipz on 10/25/20.
//

#include "Clerk.h"

Clerk::Clerk():Worker() {}

Clerk::Clerk(const long &id, const string &name, const string &surname, const Date &birthday,
             double salary, const string &mobileNumber, const string &cashRegisterInfo) : Worker(id, name, surname,
                                                                                                 birthday, "Clerk", salary,
                                                                                                 mobileNumber),
                                                                                          cashRegisterInfo(
                                                                                                  cashRegisterInfo) {}

string Clerk::Serialize() {
    return Worker::Serialize() + sep + this->cashRegisterInfo;
}

void Clerk::Parse(vector<string> *parameters) {
    Worker::Parse(parameters);
    this->cashRegisterInfo = parameters->at(0);
    parameters->erase(parameters->begin(),parameters->begin()+1);
}

const string &Clerk::getCashRegisterInfo() const {
    return cashRegisterInfo;
}

void Clerk::setCashRegisterInfo(const string &cashRegisterInfo) {
    Clerk::cashRegisterInfo = cashRegisterInfo;
}
