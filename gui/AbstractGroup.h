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
#include "gui/BusinessGUI/BusinessTableModel.h"
#include "gui/AbstractTable/Table.h"
#include "gui/AbstractDisplay/AbstractNavigationDisplayModel.h"
#include "gui/AbstractDisplay/NavigationDisplay.h"

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
    Fl_Button *back;
    Fl_Box *purposeLabel;


public:
    enum SwitchType {ALL, ONE, TWO, THREE, FOUR, FIVE};

    AbstractGroup(const char *string, const char *purpose, CRUD<T> *crud, AbstractTableModel<T> *tableModel, Fl_Window *parent);

    virtual void turnOnButtons(SwitchType switchType = ALL); // abstraktno

    virtual void turnOffButtons(SwitchType switchType = ALL); // abstraktno

    void static checkButtons(Fl_Widget *widget, void *data); // abstraktno

    static void createEventHandler(Fl_Widget *widget, void *data); // abstraktno

    virtual void create() = 0;

    static void modifyEventHandler(Fl_Widget *widget, void *data); // abstraktno

    virtual void modify() = 0;

    static void deleteEventHandler(Fl_Widget *widget, void *data); // abstraktno

    static void loadEventHandler(Fl_Widget *widget, void *data); // abstraktno

    TableSelection getSelection();

    T getSelectedEntity();

    CRUD<T> *getCrud() const; // abstraktno

    void reRender(); // abstraktno

    Fl_Button *addBackButton();

    Fl_Button *getBtnLoad() const;

    Table<T> *getTableDisplay() const;

    void setTableDisplay(Table<T> *tableDisplay);

};


#endif //CPP_UNIVERSITY_ASSIGMENT_ABSTRACTGROUP_H
