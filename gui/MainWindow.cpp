//
// Created by filipz on 1/4/21.
//

#include "MainWindow.h"
#include <FL/Fl_Table_Row.H>
#include "Table.h"
#include "AbstractEntityWindow.h"
#include "BusinessWindow.h"


MainWindow::MainWindow(const char *string, CRUDBusiness *crudBusiness,
                       CRUDDepartment *crudDepartment, CRUDWorker *crudWorker) : Fl_Group(0, 0, 1100, 458, string),
                                                                                 crudBusiness(crudBusiness),
                                                                                 crudDepartment(crudDepartment),
                                                                                 crudWorker(crudWorker) {

    AbstractTableModel<Business*> *model = new BusinessTableModel(crudBusiness->getService()->getEntities());
    this->businessGroup = new BusinessGroup("Business Window","Business Manager:",this->crudBusiness,model, (Fl_Window*) this);

    this->end();
    this->show();
}
