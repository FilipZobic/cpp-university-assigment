#ifndef CPP_UNIVERSITY_ASSIGMENT_WORKERCARD_H
#define CPP_UNIVERSITY_ASSIGMENT_WORKERCARD_H


#include <model/Business.h>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Output.H>

class WorkerCard : public Fl_Window {
private:
    Business *business;
    Worker *worker;

public:
    WorkerCard(Business *business, Worker *worker);
    Fl_Output *workerFullname;
    Fl_Output *workerPosition;
    Fl_Output *workerPhoneNumber;

    Fl_Output *businessName;
    Fl_Output *businessAddress;
    Fl_Output *businessPhoneNumber;

    virtual ~WorkerCard();
};
#endif