//
// Created by filipz on 1/6/21.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_NEWENTITYBUSINESS_H
#define CPP_UNIVERSITY_ASSIGMENT_NEWENTITYBUSINESS_H


#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Int_Input.H>
#include "../logic/CRUDBusiness.h"

using namespace std;

class NewEntityBusiness : public Fl_Window {
public:
    enum Type{New, Replace};
    NewEntityBusiness(int w, int h, const char *title, CRUDBusiness *crud, void *event = nullptr, Type type = New, Business *business = nullptr);

    static void cancelEventHandler(Fl_Widget *widget, void *data);
    static void createEventHandler(Fl_Widget *widget, void *data);

protected:
    Business *business;
    Fl_Input *name;
    Fl_Int_Input *registrationNumber;
    Fl_Int_Input *vat;

    Fl_Button *btnCancel;
    Fl_Button *btnCreate;

    CRUDBusiness *crud;
    void *event;
    Type type;

};


#endif //CPP_UNIVERSITY_ASSIGMENT_NEWENTITYBUSINESS_H
