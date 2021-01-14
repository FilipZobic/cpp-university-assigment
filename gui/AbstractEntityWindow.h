#ifndef CPP_UNIVERSITY_ASSIGMENT_ABSTRACTENTITYWINDOW_H
#define CPP_UNIVERSITY_ASSIGMENT_ABSTRACTENTITYWINDOW_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Int_Input.H>
#include "../logic/CRUDBusiness.h"
#include "AbstractGroup.h"

using namespace std;

template<typename T>
class AbstractEntityWindow : public Fl_Window {
public:
    enum Type{New, Replace};

    AbstractEntityWindow(int w, int h, const char *title, AbstractGroup<T> *eventInvoker, Type type = New, T entity = nullptr);
    virtual ~AbstractEntityWindow();
    virtual void createEventHandler() = 0;
    virtual void inputValidationCheck() = 0;
    virtual void replaceEventHandler() = 0;
    virtual T newEntity() = 0;
    virtual void fillOutInputs() = 0;
protected:
    AbstractGroup<T> *eventInvoker;
    Type type;
    T entity;

    Fl_Button *btnCancel;
    Fl_Button *btnCreate;
private:
    static void cancel(Fl_Widget *widget, void *data);
    static void create(Fl_Widget *widget, void *data);
};

#endif