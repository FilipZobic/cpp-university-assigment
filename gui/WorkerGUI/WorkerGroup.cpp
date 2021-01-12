#include "WorkerGroup.h"
#include "logic/CRUDWorker.h"
#include "DepartmentDisplayModel.h"
#include "WorkerWindow.h"

WorkerGroup::WorkerGroup(const char *string, const char *purpose, CRUD<Worker *> *crud,
                         AbstractTableModel<Worker *> *tableModel, Fl_Window *parent, vector<Department*>* businessDepartments) : AbstractGroup(string, purpose,
                                                                                                      crud, tableModel,
                                                                                                          parent) {
    this->begin();
    this->btnLoad->copy_label("SHOW CARD");
    this->btnDelete->copy_label("FIRE");
    this->btnCreate->copy_label("HIRE");
    // add event here for card
    this->annualLeaveBtn = new Fl_Button(745, 150, 165, 50);
    assignBoss = new Fl_Button (920, 150, 165, 50);
    assignBoss->copy_label("SET BOSS");
    annualLeaveBtn->copy_label("ANNUAL LEAVE");
    CRUDWorker *crudWorker = (CRUDWorker*)crud;
    Department *department = crudWorker->getDepartment();
    AbstractNavigationDisplayModel<Department*> *displayModel = new DepartmentDisplayModel(department, businessDepartments);
    display = new NavigationDisplay<Department*>(displayModel);
    this->connectButtons(display);

    this->end();
    this->show();

}


void WorkerGroup::create() {
    WorkerWindow *window = new WorkerWindow("New Department", this);
}

void WorkerGroup::modify() {
    TableSelection region = this->getSelection();
    Worker *oldWorker = this->tableModel->at(region.startRow);

    WorkerWindow *window = new WorkerWindow("Replace Department", this, WorkerWindow::Replace, oldWorker);
}

void WorkerGroup::navigatorNext() {
    Department *department = this->display->nextEntity();

    CRUDWorker *crudWorker = (CRUDWorker*)this->crud;

    crudWorker->setDepartment(department);
    this->tableDisplay->model->setEntities(department->getWorkers());
    this->reRender();
}

void WorkerGroup::navigatorPrevious() {
    Department *department = this->display->prevEntity();

    CRUDWorker *crudWorker = (CRUDWorker*)this->crud;

    crudWorker->setDepartment(department);
    this->tableDisplay->model->setEntities(department->getWorkers());
    this->reRender();
}

void WorkerGroup::createNavigator() {

}

void WorkerGroup::updateCrudAndTableModel() {

}

void WorkerGroup::turnOnButtons(AbstractGroup<Worker *>::SwitchType switchType) {
    AbstractGroup::turnOnButtons(switchType);
    this->annualLeaveBtn->activate();
    this->btnLoad->activate();
    this->assignBoss->activate();
}

void WorkerGroup::turnOffButtons(AbstractGroup<Worker *>::SwitchType switchType) {
    AbstractGroup::turnOffButtons(switchType);
    this->annualLeaveBtn->deactivate();
    this->btnLoad->deactivate();
    this->assignBoss->deactivate();
}
