//
// Created by filipz on 1/12/21.
//

#include "DepartmentDisplayModel.h"

DepartmentDisplayModel::DepartmentDisplayModel(Department *currentEntity, vector<Department*> *entities)
        : AbstractNavigationDisplayModel(currentEntity, entities) {}

Fl_Group *DepartmentDisplayModel::createDetailsDisplay() {
    return nullptr;
}

void DepartmentDisplayModel::updateDetailDisplay() {

}

string DepartmentDisplayModel::getMainDisplayText() {
    return currentEntity->getName();
}
