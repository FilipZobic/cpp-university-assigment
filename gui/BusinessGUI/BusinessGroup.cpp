#include "BusinessGroup.h"
#include "BusinessWindow.h"

BusinessGroup::BusinessGroup(const char *string,  const char *purpose, CRUD<Business *> *crud,
                             AbstractTableModel<Business *> *tableModel, Fl_Window *parent) :
                             AbstractGroup(string,purpose,crud,tableModel,parent) {
    this->end();
    this->show();
}

BusinessGroup::~BusinessGroup() {

}

void BusinessGroup::create() {
    BusinessWindow *window = new BusinessWindow("New Business", this);
}

void BusinessGroup::modify() {

    TableSelection region = this->getSelection();
    Business *oldBusiness = this->tableModel->at(region.startRow);

    BusinessWindow *window = new BusinessWindow("Replace Business", this, BusinessWindow::Replace, oldBusiness);
}
