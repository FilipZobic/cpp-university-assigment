#include "BusinessWindow.h"
#include "gui/MainWindow.h"

BusinessWindow::BusinessWindow(const char *title, AbstractGroup<Business*> *eventInvoker,
                               AbstractEntityWindow<Business *>::Type type, Business *entity)
        : AbstractEntityWindow(385, 535, title, eventInvoker, type, entity) {

    this->begin();

    this->name = new Fl_Input(115, 15, 235, 50);
    this->name->copy_label("*Name:");

    this->registrationNumber = new Fl_Int_Input(115, 75, 235, 50);
    this->registrationNumber->copy_label("*Reg. Nu.:");

    this->vat = new Fl_Int_Input(115, 135, 235, 50);
    this->vat->copy_label("*VAT:");


    this->phoneNumber = new Fl_Input(115, 195, 235, 50);
    this->phoneNumber->copy_label("*Phone Nu.:");
    this->address = new Fl_Input(115, 255, 235, 50);
    this->address->copy_label("*Address:");

    if (type == Replace) {
        this->fillOutInputs();
    }

    this->end();
    this->show();
}

void BusinessWindow::inputValidationCheck() {
    string name = this->name->value();
    string regNuStr = this->registrationNumber->value();
    string vatStr = this->vat->value();


    if (name.empty() || regNuStr.empty() || vatStr.empty()) {
        throw logic_error("Some required fields are empty");
    }
    long regNu = stol(regNuStr);
    if (regNu <= 0) {
        throw logic_error("Registration number can't be equal or lower then 0");
    }

    if (stof(vatStr) <= 0){
        throw logic_error("VAT can't be equal or lower then 0");
    }

    if (to_string(regNu).size() != 8){
        throw logic_error("Registration number must be exactly 8 numbers no leading 0");
    }

    string address = this->address->value();
    if (address.size() <= 10) {
        throw logic_error("Address must contain minimum 10 chars");
    }

    if (cuaUtil::patternPhoneNumberCheck(this->phoneNumber->value())){
        throw logic_error("Number min 7 max 15 numbers can also have leading +");
    }
}

void BusinessWindow::fillOutInputs() {
    this->name->value(this->entity->getName().c_str());
    this->registrationNumber->value(to_string(this->entity->getId()).c_str());
    this->vat->value(to_string(this->entity->getVat()).c_str());
    this->phoneNumber->value(this->entity->getPhoneNumber().c_str());
    this->address->value(this->entity->getAddress().c_str());
}

Business *BusinessWindow::newEntity() {
    Business *newBusiness = new Business(this->name->value(),
                                         stol(this->registrationNumber->value()),
                                         stol(this->vat->value()),this->phoneNumber->value(),this->address->value());
    return newBusiness;
}

void BusinessWindow::createEventHandler() {
    Business *newBusiness = newEntity();
    eventInvoker->getCrud()->createEntity(newBusiness);
    eventInvoker->reRender();
    delete this;
}


void BusinessWindow::replaceEventHandler() {
    Business *newBusiness = newEntity();

    newBusiness->setProgramId(this->entity->getProgramId());

    eventInvoker->getCrud()->replaceEntity(newBusiness);
    eventInvoker->reRender();

    delete this;
}