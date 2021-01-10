//
// Created by filipz on 1/9/21.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_ABSTRACTGROUP_H
#define CPP_UNIVERSITY_ASSIGMENT_ABSTRACTGROUP_H


#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Table.H>
#include <FL/Fl_Text_Display.H>
#include <logic/CRUDBusiness.h>
#include "BusinessTableModel.h"
#include "Table.h"

using namespace std;


struct TableSelection {int startRow, endRow, startColumn, endColumn;};

template <typename T>
class AbstractGroup : public Fl_Group {
protected:
    Table<T> *tableDisplay;
    CRUD<T> *crud;
    AbstractTableModel<T> *tableModel;

    Fl_Button *btnCreate;
    Fl_Button *btnChange;
    Fl_Button *btnDelete;
    Fl_Button *btnLoad;
    Fl_Box *purposeLabel;


public:
    enum SwitchType {ALL, ONE, TWO, THREE, FOUR, FIVE};

    AbstractGroup(const char *string, const char *purpose, CRUD<T> *crud, AbstractTableModel<T> *tableModel, Fl_Window *parent);

    void turnOnButtons(SwitchType switchType = ALL); // abstraktno

    void turnOffButtons(SwitchType switchType = ALL); // abstraktno

    void static checkButtons(Fl_Widget *widget, void *data); // abstraktno

    static void createEventHandler(Fl_Widget *widget, void *data); // abstraktno

    virtual void create() = 0;

    static void modifyEventHandler(Fl_Widget *widget, void *data); // abstraktno

    virtual void modify() = 0;

    static void deleteEventHandler(Fl_Widget *widget, void *data); // abstraktno

    static void loadEventHandler(Fl_Widget *widget, void *data); // abstraktno

    TableSelection getSelection();

    CRUD<T> *getCrud() const; // abstraktno

    void reRender(); // abstraktno
};


#endif //CPP_UNIVERSITY_ASSIGMENT_ABSTRACTGROUP_H
