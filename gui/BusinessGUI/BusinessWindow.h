#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESSWINDOW_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESSWINDOW_H

#include "gui/AbstractEntityWindow.h"

#include "BusinessGroup.h"

class BusinessWindow : public AbstractEntityWindow<Business*>{
protected:
    Fl_Input *name;
    Fl_Int_Input *registrationNumber;
    Fl_Int_Input *vat;
    Fl_Input *phoneNumber;
    Fl_Input *address;
public:
    BusinessWindow(const char *title, AbstractGroup<Business*> *eventInvoker, Type type = New, Business *entity = nullptr);

    virtual ~BusinessWindow();

    void createEventHandler() override;

    void inputValidationCheck() override;

    void fillOutInputs() override;

    void replaceEventHandler() override;

    Business *newEntity() override;


};


#endif //CPP_UNIVERSITY_ASSIGMENT_BUSINESSWINDOW_H
