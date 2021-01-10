#ifndef CPP_UNIVERSITY_ASSIGMENT_MAINWINDOW_H
#define CPP_UNIVERSITY_ASSIGMENT_MAINWINDOW_H


#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Table.H>
#include <FL/Fl_Text_Display.H>
#include <logic/CRUDBusiness.h>
#include <logic/CRUDWorker.h>
#include "BusinessTableModel.h"
#include "Table.h"
#include "BusinessGroup.h"

class MainWindow : public Fl_Group {
protected:
    CRUDBusiness *crudBusiness;
    CRUDDepartment *crudDepartment;
    CRUDWorker *crudWorker;

    BusinessGroup *businessGroup;
public:
    MainWindow(const char *string, CRUDBusiness *crudBusiness,
               CRUDDepartment *crudDepartment, CRUDWorker *crudWorker);
};


#endif
