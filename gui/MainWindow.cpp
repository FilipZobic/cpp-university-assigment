//
// Created by filipz on 1/4/21.
//

#include "MainWindow.h"
#include <FL/Fl_Table_Row.H>
#include <gui/DepartmentGUI/DepartmentTableModel.h>
#include <gui/WorkerGUI/WorkerTableModel.h>
#include "gui/AbstractTable/Table.h"
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

    mainWindow->departmentGroup->getBtnLoad()->callback(MainWindow::loadWorker, mainWindow);

    mainWindow->departmentGroup->show();
    mainWindow->end();
}

void MainWindow::loadWorker(Fl_Widget *widget, void *data) {
    MainWindow *mainWindow = (MainWindow*)data;
    mainWindow->departmentGroup->hide();

    Department *department = mainWindow->departmentGroup->getSelectedEntity();

    mainWindow->crudWorker->setDepartment(department);

    if (mainWindow->workerGroup != nullptr) {
        delete mainWindow->workerGroup;
    }

    CRUDDepartment *crudDepartment = (CRUDDepartment*)mainWindow->departmentGroup->getCrud();

    AbstractTableModel<Worker*> *model = new WorkerTableModel(mainWindow->crudWorker->getDepartment()->getWorkers());
    mainWindow->begin();
    mainWindow->workerGroup = new WorkerGroup("Worker Window", "Department Worker View:", mainWindow->crudWorker, model, (Fl_Window*) mainWindow, crudDepartment->getBusiness()->getDepartmentsConst());
    Fl_Button *backBtn = mainWindow->workerGroup->addBackButton();
    Event *event = new Event;
    event->show = mainWindow->departmentGroup;
    event->hide = mainWindow->workerGroup;
    backBtn->callback(MainWindow::connectBackButton, event);

    //mainWindow->departmentGroup->getBtnLoad()->callback(MainWindow::loadWorker, mainWindow);

    mainWindow->workerGroup->show();
    mainWindow->end();
}

void MainWindow::connectBackButton(Fl_Widget *widget, void *data) {
    Event *event = (Event*) data;
    event->hide->hide();
    event->show->show();
    delete event;
}
