//
// Created by filipz on 1/4/21.
//

#include "MainWindow.h"
#include <FL/Fl_Table_Row.H>
#include <gui/DepartmentGUI/DepartmentTableModel.h>
#include "Table.h"
#include "AbstractEntityWindow.h"
#include "gui/BusinessGUI/BusinessWindow.h"


MainWindow::MainWindow(const char *string, CRUDBusiness *crudBusiness,
                       CRUDDepartment *crudDepartment, CRUDWorker *crudWorker) : Fl_Group(0, 0, 1100, 458, string),
                                                                                 crudBusiness(crudBusiness),
                                                                                 crudDepartment(crudDepartment),
                                                                                 crudWorker(crudWorker) {

    AbstractTableModel<Business*> *model = new BusinessTableModel(crudBusiness->getService()->getEntities());
    this->businessGroup = new BusinessGroup("Business Window","Business Manager:",this->crudBusiness,model, (Fl_Window*) this);
    this->businessGroup->getBtnLoad()->callback(MainWindow::loadBusiness, this);

    this->end();
    this->show();
}

void MainWindow::loadBusiness(Fl_Widget *widget, void *data) {
    MainWindow *mainWindow = (MainWindow*)data;
    mainWindow->businessGroup->hide();

    Business *business = mainWindow->businessGroup->getSelectedEntity();

    mainWindow->crudDepartment->setBusiness(business);

    if (mainWindow->departmentGroup != nullptr) {
        delete mainWindow->departmentGroup;
    }

    AbstractTableModel<Department*> *model = new DepartmentTableModel(mainWindow->crudDepartment->getBusiness()->getDepartmentsConst());
    mainWindow->begin();
    mainWindow->departmentGroup = new DepartmentGroup("Department Window", "Business Department View:", mainWindow->crudDepartment, model, (Fl_Window*) mainWindow);
    Fl_Button *backBtn = mainWindow->departmentGroup->addBackButton();
    Event *event = new Event;
    event->show = mainWindow->businessGroup;
    event->hide = mainWindow->departmentGroup;
    backBtn->callback(MainWindow::connectBackButton, event);

    mainWindow->departmentGroup->show();
    mainWindow->end();
}

void MainWindow::loadWorker(Fl_Widget *widget, void *data) {

}

void MainWindow::connectBackButton(Fl_Widget *widget, void *data) {
    Event *event = (Event*) data;
    event->hide->hide();
    event->show->show();
    delete event;
}
