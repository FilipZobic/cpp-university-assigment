//
// Created by filipz on 1/4/21.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESSWINDOW_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESSWINDOW_H

#include "AbstractEntityWindow.h"

#include "BusinessGroup.h"

class BusinessWindow : public AbstractEntityWindow<Business*>{
public:
    BusinessWindow(const char *title, AbstractGroup<Business*> *eventInvoker, Type type = New, Business *entity = nullptr);

protected:
    Fl_Input *name;
    Fl_Int_Input *registrationNumber;
    Fl_Int_Input *vat;
public:
    void createEventHandler() override;

    void inputValidationCheck() override;

    void fillOutInputs() override;

    void replaceEventHandler() override;

    Business *newEntity() override;


};


#endif //CPP_UNIVERSITY_ASSIGMENT_BUSINESSWINDOW_H
