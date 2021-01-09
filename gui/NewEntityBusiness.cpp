//
// Created by filipz on 1/6/21.
//

#include <model/Business.h>
#include "NewEntityBusiness.h"
#include "MainWindow.h"
#include "Event.h"
#include <iostream>
#include <FL/fl_ask.H>

NewEntityBusiness::NewEntityBusiness(int w, int h, const char *title, CRUDBusiness *crud, void *event, Type type, Business *business) : Fl_Window(w, h, title), crud(crud), event(event), type(type), business(business) {

    this->name = new Fl_Input(115, 15, 235, 50);
    this->name->copy_label("*Name:");

    this->registrationNumber = new Fl_Int_Input(115, 75, 235, 50);
    this->registrationNumber->copy_label("*Reg. Nu.:");

    this->vat = new Fl_Int_Input(115, 135, 235, 50);
    this->vat->copy_label("*VAT:");

    this->btnCancel = new Fl_Button(15, 615, 140, 60, "CANCEL");
    btnCancel->callback(NewEntityBusiness::cancelEventHandler, this);

    if (this->type == New) this->btnCreate = new Fl_Button(235, 615, 140, 60, "CREATE");

    if(this->type == Replace){
        this->btnCreate = new Fl_Button(235, 615, 140, 60, "Replace");
        this->name->value(this->business->getName().c_str());
        this->registrationNumber->value(to_string(this->business->getId()).c_str());
        this->vat->value(to_string(this->business->getVat()).c_str());
    }

    btnCreate->callback(NewEntityBusiness::createEventHandler, this);

    this->set_modal();
    this->end();
}

void NewEntityBusiness::cancelEventHandler(Fl_Widget *widget, void *data) {
    NewEntityBusiness *form = (NewEntityBusiness*) data;
    delete form;
}

unsigned long len(unsigned long n)
{
    return n ? len(n/10)+1 : 0;
}

void NewEntityBusiness::createEventHandler(Fl_Widget *widget, void *data) {

    NewEntityBusiness *form = (NewEntityBusiness*) data;

    string name = form->name->value();

    string regNuStr = form->registrationNumber->value();
    string vatStr = form->vat->value();

    if (name.empty() || regNuStr.empty() || vatStr.empty()) {
        string message = "Some required fields are empty";
        fl_alert(message.c_str());
        return;
    }

    if (form->type == New) {
        try {
            Business *newBusiness = new Business(name, stol(regNuStr), stol(vatStr));
            form->crud->createEntity(newBusiness);
            MainWindow *window = (MainWindow*)form->event;
            window->reRender();
//            Event<Business*,MainWindow*> *eventData = (Event<Business*,MainWindow*> *)form->event;
//            eventData->eventInvoker->reRender();
            delete form;
        } catch (logic_error error) {
            fl_alert(error.what());
            return;
        }
    } else if (form->type == Replace) {
        try {
            Business *newBusiness = new Business(name, stol(regNuStr), stol(vatStr));

            newBusiness->setProgramId(form->business->getProgramId());

            form->crud->replaceEntity(newBusiness);

            MainWindow *window = (MainWindow*)form->event;
            window->reRender();

            delete form;
        } catch (logic_error error) {
            fl_alert(error.what());
            return;
        }
    }
}
