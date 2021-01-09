//
// Created by filipz on 1/4/21.
//

#include "MainWindow.h"
#include "NewEntityBusiness.h"
#include <FL/Fl_Table_Row.H>
#include "BusinessTable.h"
#include "Event.h"

MainWindow::MainWindow(const char *string, CRUDBusiness *crudBusiness) :
Fl_Group(0, 0, 1100, 458, string),crudBusiness(crudBusiness) {

    // Self dimensions

    // Navigation & Label
    label = new Fl_Label();



    // Buttons

    purposeLabel = new Fl_Box(20, 116, 220, 24, "Business Management:");

    btnCreate = new Fl_Button(45, 150, 165, 50, "CREATE");
    btnCreate->callback(MainWindow::createEventHandler,this);
    //btnCreate->box(FL_FLAT_BOX);

    // btnRead = new Fl_Button(220, 150, 165, 50, "READ");

    btnChange = new Fl_Button(220, 150, 165, 50,"MODIFY");
    btnChange->callback(MainWindow::modifyEventHandler, this);

    btnDelete = new Fl_Button(395, 150, 165, 50,"DELETE");
    btnDelete->callback(MainWindow::deleteEventHandler, this);

    btnLoad = new Fl_Button(570, 150, 165, 50,"LOAD");

    //745


    this->turnOffButtons();

    // Table
//    tableDisplay = new Fl_Table(0, 215, 1100, 240);
//    Fl_Table_Row *row = new Fl_Table_Row(0,0,1100,10);
//    tableDisplay->add(row);

    BusinessTableModel *model = new BusinessTableModel(crudBusiness->getService()->getEntities());
    tableDisplay = new BusinessTable(0, 215, 1100, 240, "", model);// send something

    //tableModel->updateTable();
    tableDisplay->col_header();
    tableDisplay->row_header();
    tableDisplay->callback(MainWindow::checkButtons, this);


   // this->callback();
    // this->resizable();
    this->end();
    this->show();
}

// If selected one table
void MainWindow::turnOnButtons(SwitchType switchType) {
    if (switchType == ALL) {
        btnChange->activate();
        btnDelete->activate();
        btnLoad->activate();
    } else if (switchType == ONE) {
        btnDelete->activate();
    }
}



// If selected None table
void MainWindow::turnOffButtons(SwitchType switchType) {
    btnChange->deactivate();
    btnDelete->deactivate();
    btnLoad->deactivate();
}

void MainWindow::checkButtons(Fl_Widget *widget, void *data) {
    MainWindow *mainWindow = (MainWindow*)data;
    int startRow;
    int endRow;
    int colLeft;
    int colRight;
    mainWindow->tableDisplay->get_selection(startRow, colLeft, endRow, colRight);

    mainWindow->turnOffButtons();

    if (startRow != -1){
        if( startRow == endRow) {
            mainWindow->turnOnButtons();
        }else {
            mainWindow->turnOnButtons(ONE);
        }
    }

    cout << startRow << " " << endRow << " " << colLeft << " " << colRight << endl;
}

void MainWindow::createEventHandler(Fl_Widget *widget, void *data) {
    MainWindow *mainWindow = (MainWindow*)data;

    //Event<Business*,MainWindow*> event(nullptr, mainWindow);
    NewEntityBusiness *window = new NewEntityBusiness(385, 685, "New Business", mainWindow->getCrudBusiness(), mainWindow);
    //window->callback(MainWindow::reRender, mainWindow);

    window->show();
    // on close delete the pointer
}

void MainWindow::readEventHandler(Fl_Widget *widget, void *data) {

}

void MainWindow::modifyEventHandler(Fl_Widget *widget, void *data) {
    MainWindow *mainWindow = (MainWindow*)data;

    // this can be its own function
    int startRow;
    int endRow;
    int colLeft;
    int colRight;
    mainWindow->tableDisplay->get_selection(startRow, colLeft, endRow, colRight);

    Business *oldBusiness = mainWindow->tableDisplay->model->at(startRow);

    cout << oldBusiness->Serialize() << endl;


//    Event event;
//    event.pFunction = mainWindow->reRender;
    //Event<Business*,MainWindow*> event(oldBusiness, mainWindow);

    NewEntityBusiness *window = new NewEntityBusiness(385, 685, "Replace Business", mainWindow->getCrudBusiness(), mainWindow, NewEntityBusiness::Replace, oldBusiness);
    window->show();
}

void MainWindow::deleteEventHandler(Fl_Widget *widget, void *data) {
    MainWindow *mainWindow = (MainWindow*)data;

    int startRow;
    int endRow;
    int colLeft;
    int colRight;
    mainWindow->tableDisplay->get_selection(startRow, colLeft, endRow, colRight);


    for(int i = endRow ; i >= startRow ; i--){
        cout << i << endl;
        long id = mainWindow->tableDisplay->model->at(i)->getId();
        mainWindow->crudBusiness->removeEntity(id);
    }
    mainWindow->turnOffButtons();
    mainWindow->reRender();
}

void MainWindow::loadEventHandler(Fl_Widget *widget, void *data) {

}

CRUDBusiness *MainWindow::getCrudBusiness() const {
    return crudBusiness;
}

void MainWindow::reRender() {
    cout << "ACTIVATED" << endl;
    this->tableDisplay->updateRows();
    this->tableDisplay->redraw();
}
