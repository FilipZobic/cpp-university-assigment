#ifndef CPP_UNIVERSITY_ASSIGMENT_WORKERWINDOW_H
#define CPP_UNIVERSITY_ASSIGMENT_WORKERWINDOW_H


#include <model/Worker.h>
#include "gui/AbstractEntityWindow.h"
#include <Fl/Fl_Float_Input.H>
#include <Fl/Fl_Int_Input.H>
#include <Fl/Fl_Input_Choice.H>

class WorkerWindow : public AbstractEntityWindow<Worker*> {
protected:
    Fl_Input *name;
    Fl_Input *surname;
    Fl_Input *birthDay; // pattern
    Fl_Input_Choice *workerType;
    Fl_Float_Input *salary;
    Fl_Input *phoneNumber; // pattern

    Fl_Input *clerkInfo;

    Fl_Int_Input *driverInfractions;
    Fl_Input *driverLicenses; // pattern

public:
    WorkerWindow(const char *title, AbstractGroup<Worker *> *eventInvoker, Type type = New,
                 Worker *entity = nullptr);

    void createEventHandler() override;

    void inputValidationCheck() override;

    void replaceEventHandler() override;

    Worker *newEntity() override;

    void fillOutInputs() override;

    static void checkWorkerType(Fl_Widget *widget, void *data);

    string getWorkerType();

    bool patternCheckDrivingLicenses();

    bool patternPhoneNumberCheck();
};


#endif
