//
// Created by filipz on 1/4/21.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_MAINWINDOW_H
#define CPP_UNIVERSITY_ASSIGMENT_MAINWINDOW_H


#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Table.H>
#include <FL/Fl_Text_Display.H>
#include <logic/CRUDBusiness.h>
#include "BusinessTableModel.h"
#include "NewEntityBusiness.h"
#include "Table.h"

class MainWindow : public Fl_Group {
protected:
    // Logic
    CRUDBusiness *crudBusiness;

    // Navigation & Label
    Fl_Label *label;

    // Buttons
    Fl_Button *btnCreate;
    Fl_Button *btnChange;
    Fl_Button *btnDelete;
    Fl_Button *btnLoad;
    Fl_Box *purposeLabel;

    // Table
    Table<Business*> *tableDisplay;

public:
    enum SwitchType {ALL, ONE, TWO, THREE, FOUR, FIVE};
    MainWindow(const char *string, CRUDBusiness *crudBusiness);

    void turnOnButtons(SwitchType switchType = ALL);

    void turnOffButtons(SwitchType switchType = ALL);

    void static checkButtons(Fl_Widget *widget, void *data);

    static void createEventHandler(Fl_Widget *widget, void *data);

    static void readEventHandler(Fl_Widget *widget, void *data);

    static void modifyEventHandler(Fl_Widget *widget, void *data);

    static void deleteEventHandler(Fl_Widget *widget, void *data);

    static void loadEventHandler(Fl_Widget *widget, void *data);

    CRUDBusiness *getCrudBusiness() const;

    void reRender();
};


#endif //CPP_UNIVERSITY_ASSIGMENT_MAINWINDOW_H
