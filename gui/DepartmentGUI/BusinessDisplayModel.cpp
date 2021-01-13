#include "util/Util.h"
#include <Fl/Fl_Output.H>
#include "BusinessDisplayModel.h"

BusinessDisplayModel::BusinessDisplayModel(Business *currentEntity, vector<Business*> *entities)
        : AbstractNavigationDisplayModel(currentEntity, entities) {}

Fl_Group *BusinessDisplayModel::createDetailsDisplay() {
    Fl_Group *flGroup = new Fl_Group(775,15,290,110);
    flGroup->begin();
    a1 = new Fl_Output(865,35,40,25);
    a1->copy_label("Nu. W. Men");
    a2 = new Fl_Output(865,85,40,25);
    a2->copy_label("Nu. Clerks");
    a3 = new Fl_Output(865,135,40,25);
    a3->copy_label("Nu. Drivers");
    a5 = new Fl_Output(920,35,145,25);
    a5->copy_label("Serial Number:");
    a5->align(FL_ALIGN_TOP);
    a6 = new Fl_Output(920,85,145,25);
    a6->copy_label("VAT:");
    a6->align(FL_ALIGN_TOP);
    a7 = new Fl_Output(920,135,145,25);
    a7->copy_label("Spending:");
    a7->textcolor(FL_RED);
    a7->align(FL_ALIGN_TOP);
    flGroup->show();
    flGroup->end();

    return flGroup;
}

string BusinessDisplayModel::getMainDisplayText() {
    return this->currentEntity->getName();
}

void BusinessDisplayModel::updateDetailDisplay() {
    a1->value(to_string(this->currentEntity->getNumberOfSpecificWorker(Department::Warehouseman)).c_str());
    a2->value(to_string(this->currentEntity->getNumberOfSpecificWorker(Department::Clerk)).c_str());
    a3->value(to_string(this->currentEntity->getNumberOfSpecificWorker(Department::Driver)).c_str());
    a5->value(to_string(this->currentEntity->getId()).c_str());
    a6->value(to_string(this->currentEntity->getVat()).c_str());
    a7->value(cuaUtil::roundDouble(this->currentEntity->calculateSpending()).c_str());
}
