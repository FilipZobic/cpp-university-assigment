//
// Created by filipz on 1/10/21.
//

#include "DepartmentGroup.h"
#include "DepartmentWindow.h"

DepartmentGroup::DepartmentGroup(const char *string, const char *purpose, CRUD<Department *> *crud,
                                 AbstractTableModel<Department *> *tableModel, Fl_Window *parent) : AbstractGroup(
        string, purpose, crud, tableModel, parent) {
    this->begin();
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
