#include "WorkerGroup.h"
#include "logic/CRUDWorker.h"
#include "DepartmentDisplayModel.h"
#include "WorkerWindow.h"
#include "AnnualLeaveWindow.h"
#include "WorkerCard.h"

WorkerGroup::WorkerGroup(const char *string, const char *purpose, CRUD<Worker *> *crud,
                         AbstractTableModel<Worker *> *tableModel, Fl_Window *parent, vector<Department*>* businessDepartments) : AbstractGroup(string, purpose,
                                                                                                      crud, tableModel,
                                                                                                          parent) {
    this->begin();
    this->btnLoad->copy_label("SHOW CARD");
    this->btnLoad->callback(WorkerGroup::loadWorkerCard,this);
    this->btnDelete->copy_label("FIRE");
    this->btnCreate->copy_label("HIRE");
    // add event here for card
    this->annualLeaveBtn = new Fl_Button(745, 150, 165, 50);
    this->annualLeaveBtn->callback(WorkerGroup::annualLeaveEventHandler,this);
    assignBoss = new Fl_Button (920, 150, 165, 50);
    assignBoss->copy_label("SET BOSS");
    assignBoss->callback(WorkerGroup::assignBossHandler, this);
    annualLeaveBtn->copy_label("ANNUAL LEAVE");
    CRUDWorker *crudWorker = (CRUDWorker*)crud;
    Department *department = crudWorker->getDepartment();
    AbstractNavigationDisplayModel<Department*> *displayModel = new DepartmentDisplayModel(department, businessDepartments);
    display = new NavigationDisplay<Department*>(displayModel);
    this->connectButtons(display);

    this->turnOffButtons(ALL);

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
    this->turnOffButtons(ALL);
    this->tableDisplay->model->setEntities(department->getWorkers());
    this->reRender();
}

void WorkerGroup::navigatorPrevious() {
    Department *department = this->display->prevEntity();

    CRUDWorker *crudWorker = (CRUDWorker*)this->crud;

    crudWorker->setDepartment(department);
    this->tableDisplay->model->setEntities(department->getWorkers());
    this->turnOffButtons(ALL);
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

void WorkerGroup::annualLeaveEventHandler(Fl_Widget *widget, void *data) {
    WorkerGroup *workerWindow = (WorkerGroup*)data;
    TableSelection region = workerWindow->getSelection();
    Worker *oldWorker = workerWindow->tableModel->at(region.startRow);
    AnnualLeaveWindow *window = new AnnualLeaveWindow("Add Annual Leave", workerWindow, WorkerWindow::New, oldWorker);
}

void WorkerGroup::reRender() {
    AbstractGroup::reRender();
    this->display->reRender();
}

void WorkerGroup::assignBossHandler(Fl_Widget *widget, void *data) {
    WorkerGroup *workerWindow = (WorkerGroup*)data;
    TableSelection region = workerWindow->getSelection();
    Worker *worker = workerWindow->tableModel->at(region.startRow);
    CRUDWorker *crudWorker = (CRUDWorker*)workerWindow->crud;
    crudWorker->setBoss(worker);
    workerWindow->reRender();
}

void WorkerGroup::loadWorkerCard(Fl_Widget *widget, void *data) {
    WorkerGroup *workerWindow = (WorkerGroup*)data;
    CRUDWorker *crudWorker = (CRUDWorker*)workerWindow->crud;
    TableSelection region = workerWindow->getSelection();
    Worker *worker = workerWindow->tableModel->at(region.startRow);
    Business *business = (Business*)crudWorker->getDepartment()->getBusiness();
    WorkerCard *window = new WorkerCard(business,worker);
}
