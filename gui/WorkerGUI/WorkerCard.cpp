#include "WorkerCard.h"

WorkerCard::WorkerCard(Business *business, Worker *worker) : Fl_Window(500, 200, "Worker Card"),
                                                                                              business(business),
                                                                                              worker(worker) {
    this->begin();
    workerFullname = new Fl_Output(30,30,195,30);
    workerFullname->copy_label("Fullname:");
    workerFullname->align(FL_ALIGN_TOP_LEFT);
    workerFullname->insert(this->worker->getFullName().c_str());

    workerPosition = new Fl_Output(30,78,195,30);
    workerPosition->copy_label("Position:");
    workerPosition->align(FL_ALIGN_TOP_LEFT);
    workerPosition->insert(this->worker->getType().c_str());

    workerPhoneNumber = new Fl_Output(30,126,195,30);
    workerPhoneNumber->copy_label("Personal Phone:");
    workerPhoneNumber->align(FL_ALIGN_TOP_LEFT);
    workerPhoneNumber->insert(this->worker->getMobileNumber().c_str());

    businessName = new Fl_Output(235,30,236,30);
    businessName->copy_label("Business");
    businessName->align(FL_ALIGN_TOP_LEFT);
    businessName->insert(this->business->getName().c_str());

    businessAddress = new Fl_Output(235,78,236,30);
    businessAddress->copy_label("Business Address:");
    businessAddress->align(FL_ALIGN_TOP_LEFT);
    businessAddress->insert(this->business->getAddress().c_str());

    businessPhoneNumber = new Fl_Output(235,126,236,30);
    businessPhoneNumber->copy_label("Business Phone:");
    businessPhoneNumber->align(FL_ALIGN_TOP_LEFT);
    businessPhoneNumber->insert(this->business->getPhoneNumber().c_str());
    this->set_modal();
    this->end();
    this->show();
}

WorkerCard::~WorkerCard() {
    delete workerFullname;
    delete workerPosition;
    delete workerPhoneNumber;

    delete businessName;
    delete businessAddress;
    delete businessPhoneNumber;
}