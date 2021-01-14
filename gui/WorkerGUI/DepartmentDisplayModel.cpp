//
// Created by filipz on 1/12/21.
//

#include "DepartmentDisplayModel.h"
#include "util/Util.h"
#include "model/Business.h"
DepartmentDisplayModel::DepartmentDisplayModel(Department *currentEntity, vector<Department*> *entities)
        : AbstractNavigationDisplayModel(currentEntity, entities) {
}

Fl_Group *DepartmentDisplayModel::createDetailsDisplay() {
    Fl_Group *flGroup = new Fl_Group(775,15,290,115);
    flGroup->begin();
    boss = new Fl_Output(780,40,145,25);
    boss->copy_label("Current Boss");
    boss->align(FL_ALIGN_TOP);
    spending = new Fl_Output(780,90,145,25);
    spending->copy_label("Spending:");
    spending->align(FL_ALIGN_TOP);
    spending->textcolor(FL_RED);
    businessName = new Fl_Output(935,40,120,25);
    businessName->copy_label("Business Name:");
    businessName->align(FL_ALIGN_TOP);
    flGroup->end();
    return flGroup;
}

void DepartmentDisplayModel::updateDetailDisplay() {
    this->boss->value(this->currentEntity->getBossName().c_str());
    this->spending->value(cuaUtil::roundDouble(-this->currentEntity->getSpending()).c_str());
    Business *business = (Business*)this->currentEntity->getBusiness();
    businessName->value(business->getName().c_str());
}

string DepartmentDisplayModel::getMainDisplayText() {
    return currentEntity->getName();
}
