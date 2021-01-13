//
// Created by filipz on 1/10/21.
//

#include "DepartmentGroup.h"
#include "DepartmentWindow.h"
#include "BusinessDisplayModel.h"
#include "util/Util.h"
DepartmentGroup::DepartmentGroup(const char *string, const char *purpose, CRUD<Department *> *crud,
                                 AbstractTableModel<Department *> *tableModel, Fl_Window *parent) : AbstractGroup(
        string, purpose, crud, tableModel, parent), AbstractNavigatorImplementation<Business*>() {
    this->begin();

    CRUDDepartment *crudDepartment = (CRUDDepartment*)crud;
    Business *business = crudDepartment->getBusiness();
    AbstractNavigationDisplayModel<Business*> *displayModel = new BusinessDisplayModel(business, crudDepartment->getBusinessServiceVector());
    display = new NavigationDisplay<Business*>(displayModel);
    this->connectButtons(display);

    this->end();
    this->show();
}

void DepartmentGroup::create() {
    DepartmentWindow *window = new DepartmentWindow("New Department", this);
}

void DepartmentGroup::modify() {
    TableSelection region = this->getSelection();
    Department *oldDepartment = this->tableModel->at(region.startRow);

    DepartmentWindow *window = new DepartmentWindow("Replace Department", this, DepartmentWindow::Replace, oldDepartment);
}

void DepartmentGroup::navigatorNext() {
    Business *business = this->display->nextEntity();

    CRUDDepartment *crudDepartment = (CRUDDepartment*)this->crud;

    crudDepartment->setBusiness(business);
    this->tableDisplay->model->setEntities(business->getDepartmentsConst());
    this->turnOffButtons(ALL);

    this->reRender();
}

void DepartmentGroup::navigatorPrevious() {
    Business *business = this->display->prevEntity();

    CRUDDepartment *crudDepartment = (CRUDDepartment*)this->crud;

    crudDepartment->setBusiness(business);
    this->tableDisplay->model->setEntities(business->getDepartmentsConst());
    this->turnOffButtons(ALL);
    this->reRender();
}

// constructor ide
void DepartmentGroup::createNavigator(){

}

void DepartmentGroup::updateCrudAndTableModel() {

}
