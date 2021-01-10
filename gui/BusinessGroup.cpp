#include "BusinessGroup.h"
#include "BusinessWindow.h"

void BusinessGroup::create() {
    BusinessWindow *window = new BusinessWindow("New Business", this);
    window->show();
}

void BusinessGroup::modify() {

    TableSelection region = this->getSelection();
    Business *oldBusiness = this->tableModel->at(region.startRow);

    BusinessWindow *window = new BusinessWindow("New Business", this, BusinessWindow::Replace, oldBusiness);
    window->show();
}

BusinessGroup::BusinessGroup(const char *string,  const char *purpose, CRUD<Business *> *crud,
                             AbstractTableModel<Business *> *tableModel, Fl_Window *parent) : AbstractGroup(string,
                                                                                                            purpose,
                                                                                                            crud,
                                                                                                            tableModel,
                                                                                                            parent) {
    this->end();
    this->show();
}
