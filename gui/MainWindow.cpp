//
// Created by filipz on 1/4/21.
//

#include "MainWindow.h"

MainWindow::MainWindow(const char *string, CRUDBusiness *crudBusiness) :
Fl_Group(0, 0, 1100, 458, string),crudBusiness(crudBusiness) {
    businesses = crudBusiness->getService()->getEntities();

    // Self dimensions

    // Navigation & Label
    label = new Fl_Label();



    // Buttons
    btnCreate = new Fl_Button(45, 150, 165, 50, "CREATE");
    //btnCreate->box(FL_FLAT_BOX);

    btnRead = new Fl_Button(220, 150, 165, 50, "READ");

    btnChange = new Fl_Button(395, 150, 165, 50,"MODIFY");

    btnDelete = new Fl_Button(570, 150, 165, 50,"DELETE");

    btnLoad = new Fl_Button(745, 150, 165, 50,"LOAD");

    this->turnOffButtons();

    // Table
    tableDisplay = new Fl_Table(0, 215, 1100, 240);

    //
    // this->resizable();
    this->end();
    this->show();
}

// If selected one table
void MainWindow::turnOnButtons() {
    btnRead->set();
    btnChange->set();
    btnDelete->set();
    btnLoad->set();
}

// If selected None table
void MainWindow::turnOffButtons() {
    btnRead->clear();
    btnChange->clear();
    btnDelete->clear();
    btnLoad->clear();
    btnCreate->callback(MainWindow::createEventHandler,this);
}

void MainWindow::createEventHandler(Fl_Widget *widget, void *data) {

}

void MainWindow::readEventHandler(Fl_Widget *widget, void *data) {

}

void MainWindow::modifyEventHandler(Fl_Widget *widget, void *data) {

}

void MainWindow::deleteEventHandler(Fl_Widget *widget, void *data) {

}

void MainWindow::loadEventHandler(Fl_Widget *widget, void *data) {

}
