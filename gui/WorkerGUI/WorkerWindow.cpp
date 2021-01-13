//
// Created by filipz on 1/4/21.
//

#include "WorkerWindow.h"
#include <regex>
using namespace std;

WorkerWindow::WorkerWindow(const char *title, AbstractGroup<Worker *> *eventInvoker,
                           AbstractEntityWindow<Worker *>::Type type,Worker *entity) : AbstractEntityWindow(385, 685,
                                                                                                                   title,
                                                                                                                   eventInvoker,
                                                                                                                   type,
                                                                                                                   entity) {
    this->begin();
    this->name = new Fl_Input(115, 15, 235, 50);
    this->name->copy_label("*Name:");
    this->surname = new Fl_Input(115, 75, 235, 50);
    surname->copy_label("*Surname:");
    this->birthDay = new Fl_Input(115, 135, 235, 50);
    this->birthDay->value("dd/mm/yyyy");
    birthDay->copy_label("*Birthday:");
    workerType = new Fl_Input_Choice(115, 195, 240, 50);
    workerType->copy_label("*Type");
    workerType->add("Warehouseman");
    workerType->add("Clerk");
    workerType->add("Driver");
    workerType->value(0);
    workerType->callback(WorkerWindow::checkWorkerType, this);
    this->salary = new Fl_Float_Input(115, 255, 235, 50);
    this->salary->copy_label("*Salary:");
    this->phoneNumber = new Fl_Input(115, 315, 240, 50);
    this->phoneNumber->copy_label("*Phone Nu.:");

    clerkInfo = new Fl_Input(115, 375, 240, 50);
    clerkInfo->copy_label("Register Info:");

    driverInfractions = new Fl_Int_Input(115, 375, 240, 50);
    driverInfractions->copy_label("*Nu. Infractions:");

    driverLicenses = new Fl_Input(115, 435, 240 ,50);
    driverLicenses->value("x1,xx");
    driverLicenses->copy_label("*Licenses:");

    workerType->do_callback();
    if (type == Replace) {
        this->fillOutInputs();
    }
    this->end();
}

void WorkerWindow::createEventHandler() {
    string type = getWorkerType();

    Worker *worker = newEntity();

    eventInvoker->getCrud()->createEntity(worker);
    eventInvoker->reRender();
    delete this;
}

void WorkerWindow::inputValidationCheck() {
    string type = getWorkerType();

    string name = this->name->value();
    string surname = this->surname->value();
    string salary = this->salary->value();

    if (name.empty() || surname.empty() || salary.empty()){
        throw logic_error("Some fields are empty");
    }

    if (stol(salary) <= 0){
        throw logic_error("Salary can't be lower or equal to 0");
    }

    if (this->patternPhoneNumberCheck()){
        throw logic_error("Number min 7 max 15 numbers can also have leading +");
    }

    if (Date::patternCheckDate(this->birthDay->value())){
        throw logic_error("Date is invalid use: dd/mm/yyyy");
    }
    if (type == "Warehouseman"){

    }else if (type == "Clerk"){
        string clerkInfo = this->clerkInfo->value();
    }else if (type == "Driver"){
        string infra = this->driverInfractions->value();
        if (infra.empty()){
            throw logic_error("Number of infractions is empty");
        }
        if (stoi(infra) < 0) {
            throw logic_error("Number of infractions can't be lower then 0");
        }
        if (this->patternCheckDrivingLicenses()){
            throw logic_error("Driving license format example A1,B1,BA");
        }
    }else {
        throw logic_error("Sent type does not exist");
    }
}

void WorkerWindow::replaceEventHandler() {
    string type = getWorkerType();

    Worker *worker = newEntity();
    worker->setId(this->entity->getId());

    worker->copyAnnualLeave(this->entity->getAnnualLeave());

    eventInvoker->getCrud()->replaceEntity(worker);
    eventInvoker->reRender();
    delete this;
}

Worker *WorkerWindow::newEntity() {
    string type = getWorkerType();
    Worker *newWorker;

    string name = this->name->value();
    string surname = this->surname->value();
    double salary = stod(this->salary->value());
    Date date;
    string toSend = this->birthDay->value();
    date.Parse(toSend);
    string number = this->phoneNumber->value();

    if (type == "Warehouseman"){
        newWorker = new Warehouseman(0,name,surname,date,salary,number);
    }
    else if (type == "Clerk"){
        newWorker = new Clerk(0,name,surname,date,salary,number, this->clerkInfo->value());
    }else if (type == "Driver"){
        newWorker = new Driver(0,name,surname,date,salary,number,stoi(this->driverInfractions->value()));
        Driver* driver = (Driver*)newWorker;

        string licenses = this->driverLicenses->value();

        std::regex r("[A-Z]{1}[0-9A-Z]{0,1}");

        for(std::sregex_iterator i = std::sregex_iterator(licenses.begin(), licenses.end(), r);
            i != std::sregex_iterator();
            ++i ) {
            std::smatch m = *i;
            driver->addDrivingCategory(m.str());
        }
    }

    return newWorker;
}

void WorkerWindow::fillOutInputs() {
    string type = entity->getType();

    this->name->value(entity->getName().c_str());
    this->surname->value(entity->getSurname().c_str());
    this->salary->value(to_string(entity->getSalary()).c_str());
    this->birthDay->value(entity->getBirthday().toString().c_str());
    this->phoneNumber->value(entity->getMobileNumber().c_str());

    if (type == "Warehouseman"){
        this->workerType->value(0);
        this->workerType->do_callback();

    }else if (type == "Clerk"){
        this->workerType->value(1);
        Clerk *clerk = (Clerk*)this->entity;
        this->clerkInfo->value(clerk->getCashRegisterInfo().c_str());
        this->workerType->do_callback();

    }else if (type == "Driver"){
        this->workerType->value(2);
        Driver *driver = (Driver*)this->entity;
        this->driverInfractions->value(to_string(driver->getNumTrafficInfractions()).c_str());

        this->driverLicenses->value(driver->drivingCategoriesToString().c_str());
        this->workerType->do_callback();

    }else {
        throw logic_error("Sent type does not exist");
    }

}

void WorkerWindow::checkWorkerType(Fl_Widget *widget, void *data) {
    WorkerWindow *workerWindow = (WorkerWindow*)data;
    string type = workerWindow->getWorkerType();

    workerWindow->clerkInfo->hide();
    workerWindow->driverInfractions->hide();
    workerWindow->driverLicenses->hide();

    if (type=="Warehouseman"){

    }else if(type=="Clerk"){
        workerWindow->clerkInfo->show();
    }else if(type=="Driver"){
        workerWindow->driverInfractions->show();
        workerWindow->driverLicenses->show();
    }else{
        throw logic_error("None existing type!");
    }
}

// ovo ide u crud worker
string WorkerWindow::getWorkerType() {
    return this->workerType->value();
}

bool WorkerWindow::patternCheckDrivingLicenses() {
    string drivingLicenses = this->driverLicenses->value();
    if (drivingLicenses.empty()){
        return true;
    }

    regex pattern("\\s*|\\,*");
    drivingLicenses = regex_replace(drivingLicenses,pattern,"");
    pattern.assign("([A-Z]{1}[0-9A-Z]{0,1})*");

    if (!regex_match(drivingLicenses,pattern)){
        return true;
    }
    string whatsLeft = regex_replace(drivingLicenses,pattern,"");
    if (!whatsLeft.empty()){
        return true;
    }

    return false;
}
// ovo ide u crud worker

bool WorkerWindow::patternPhoneNumberCheck() {
    string number = this->phoneNumber->value();
    if (number.empty()){
        return true;
    }
    if (regex_match(number,regex("\\[a-Z]"))){
        return true;
    }

    regex pattern("\\s*|\\/*\\-*");
    number = regex_replace(number,pattern,"");

    if (!regex_match(number,regex("\\+{0,1}[0-9]{7,15}"))){
        return true;
    }

    return false;
}