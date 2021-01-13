#ifndef CPP_UNIVERSITY_ASSIGMENT_ABSTRACTNAVIGATORIMPLEMENTATION_H
#define CPP_UNIVERSITY_ASSIGMENT_ABSTRACTNAVIGATORIMPLEMENTATION_H
#include "NavigationDisplay.h"
#include <logic/CRUD.h>
#include "util/Util.h"

template <typename T>
class AbstractNavigatorImplementation {
protected:
    NavigationDisplay<T> *display;
public:
    AbstractNavigatorImplementation();

    static void navigatorNextHandler(Fl_Widget *widget, void* data);
    static void navigatorPreviousHandler(Fl_Widget *widget, void* data);
    void connectButtons(NavigationDisplay<T> *display);
    virtual void navigatorNext() = 0;
    virtual void navigatorPrevious() = 0;
    virtual void createNavigator() = 0;
    virtual void updateCrudAndTableModel() = 0;

    NavigationDisplay<T> *getDisplay() const;

    void setDisplay(NavigationDisplay<T> *display);
};

#endif
