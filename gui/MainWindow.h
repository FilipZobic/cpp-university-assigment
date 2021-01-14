#ifndef CPP_UNIVERSITY_ASSIGMENT_MAINWINDOW_H
#define CPP_UNIVERSITY_ASSIGMENT_MAINWINDOW_H


#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Table.H>
#include <FL/Fl_Text_Display.H>
#include <logic/CRUDBusiness.h>
#include <logic/CRUDWorker.h>
#include <gui/WorkerGUI/WorkerGroup.h>
#include "gui/BusinessGUI/BusinessTableModel.h"
#include "gui/AbstractTable/Table.h"
#include "gui/BusinessGUI/BusinessGroup.h"
#include "gui/DepartmentGUI/DepartmentGroup.h"

class MainWindow : public Fl_Group {
protected:
    CRUDBusiness *crudBusiness;
    CRUDDepartment *crudDepartment;
    CRUDWorker *crudWorker;

    BusinessGroup *businessGroup;
    DepartmentGroup *departmentGroup = nullptr;
    WorkerGroup *workerGroup = nullptr;
public:
    MainWindow(const char *string, CRUDBusiness *crudBusiness,
               CRUDDepartment *crudDepartment, CRUDWorker *crudWorker);

    virtual ~MainWindow();

    static void loadBusiness(Fl_Widget *widget, void *data);
    static void loadDepartment(Fl_Widget *widget, void *data);

    struct Event{Fl_Group *hide; Fl_Group *show;};
    static void connectBackButton(Fl_Widget *widget, void *data);
};

#endif