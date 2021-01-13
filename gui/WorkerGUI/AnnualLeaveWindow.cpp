//
// Created by filipz on 1/4/21.
//

#include "AnnualLeaveWindow.h"

void AnnualLeaveWindow::createEventHandler() {
    string startDateString = this->startDate->value();
    string endDateString = this->endDate->value();

    Date dateStart;
    Date dateEnd;
    dateStart.Parse(startDateString);
    dateEnd.Parse(endDateString);

    AnnualLeave *annualLeave = new AnnualLeave(dateStart,dateEnd);

    this->entity->setAnnualLeave(annualLeave);
    this->eventInvoker->reRender();
    delete this;
}

void AnnualLeaveWindow::inputValidationCheck() {
    string startDateString = this->startDate->value();
    string endDateString = this->endDate->value();

    bool isStarBad = Date::patternCheckDate(startDateString);
    bool isEndBad = Date::patternCheckDate(startDateString);

    if (isStarBad || isEndBad){
        throw logic_error("Date is invalid use: dd/mm/yyyy");
    }
}

void AnnualLeaveWindow::replaceEventHandler() {

}

Worker *AnnualLeaveWindow::newEntity() {
    return nullptr;
}

void AnnualLeaveWindow::fillOutInputs() {
    this->startDate->value(this->entity->getAnnualLeave()->getStart().toString().c_str());
    this->endDate->value(this->entity->getAnnualLeave()->getAnEnd().toString().c_str());
}

AnnualLeaveWindow::AnnualLeaveWindow(const char *title, AbstractGroup<Worker *> *eventInvoker,
                                     AbstractEntityWindow<Worker *>::Type type,Worker *entity)
        : AbstractEntityWindow(525, 185, title, eventInvoker, type, entity) {
    this->begin();
    startDate = new Fl_Input(20,35,235,50);
    endDate = new Fl_Input(270,35,235,50);
    this->end();
}
