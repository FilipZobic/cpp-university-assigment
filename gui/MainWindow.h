//
// Created by filipz on 1/4/21.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_MAINWINDOW_H
#define CPP_UNIVERSITY_ASSIGMENT_MAINWINDOW_H


#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Table.H>
#include <logic/CRUDBusiness.h>

class MainWindow : public Fl_Group {
protected:
    // Logic
    CRUDBusiness *crudBusiness;
    vector<Business*> *businesses;

    // Navigation & Label
    Fl_Label *label;

    // Buttons
    Fl_Button *btnCreate;
    Fl_Button *btnRead;
    Fl_Button *btnChange;
    Fl_Button *btnDelete;
    Fl_Button *btnLoad;

    // Table
    Fl_Table *tableDisplay;

public:
    MainWindow(const char *string, CRUDBusiness *crudBusiness);

    void turnOnButtons();

    void turnOffButtons();

    virtual void createEventHandler(Fl_Widget *widget, void *data);

    virtual void readEventHandler(Fl_Widget *widget, void *data);

    virtual void modifyEventHandler(Fl_Widget *widget, void *data);

    virtual void deleteEventHandler(Fl_Widget *widget, void *data);

    virtual void loadEventHandler(Fl_Widget *widget, void *data);
};


#endif //CPP_UNIVERSITY_ASSIGMENT_MAINWINDOW_H
