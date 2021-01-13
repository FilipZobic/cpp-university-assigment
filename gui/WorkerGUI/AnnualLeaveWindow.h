//
// Created by filipz on 1/4/21.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_ANNUALLEAVEWINDOW_H
#define CPP_UNIVERSITY_ASSIGMENT_ANNUALLEAVEWINDOW_H


#include <model/Worker.h>
#include "gui/AbstractEntityWindow.h"

class AnnualLeaveWindow : public AbstractEntityWindow <Worker*> {
protected:
    Fl_Input *startDate;
    Fl_Input *endDate;
public:
    AnnualLeaveWindow(const char *title, AbstractGroup<Worker *> *eventInvoker, Type type,
                      Worker *entity);

    void createEventHandler() override;

    void inputValidationCheck() override;

    void replaceEventHandler() override;

    Worker *newEntity() override;

    void fillOutInputs() override;
};


#endif //CPP_UNIVERSITY_ASSIGMENT_ANNUALLEAVEWINDOW_H
