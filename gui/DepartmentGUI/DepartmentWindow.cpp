#include "DepartmentWindow.h"

DepartmentWindow::DepartmentWindow(const char *title, AbstractGroup<Department *> *eventInvoker,
                                   AbstractEntityWindow<Department *>::Type type, Department *entity)
        : AbstractEntityWindow(385, 415, title, eventInvoker, type, entity) {
    this->begin();
    this->name = new Fl_Input(115, 15, 235, 50);
    this->name->copy_label("*Name:");

    if (type == Replace) {
        this->fillOutInputs();
    }
    this->end();
}

void DepartmentWindow::createEventHandler() {
    Department *Department = newEntity();
    eventInvoker->getCrud()->createEntity(Department);
    eventInvoker->reRender();
    delete this;
}

void DepartmentWindow::inputValidationCheck() {
    string name = this->name->value();

    if (name.empty()) {
        throw logic_error("Name is required");
    }
}

void DepartmentWindow::replaceEventHandler() {
    Department *newDepartment = newEntity();

    newDepartment->setId(this->entity->getId());

    eventInvoker->getCrud()->replaceEntity(newDepartment);
    eventInvoker->reRender();

    delete this;
}

Department *DepartmentWindow::newEntity() {
    Department *department = new Department(this->name->value());
    return department;
}

void DepartmentWindow::fillOutInputs() {
    cout << this->entity->getName() << endl;
    this->name->value(this->entity->getName().c_str());
}