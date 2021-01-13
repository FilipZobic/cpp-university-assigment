#include "AnnualLeaveWindow.h"

AnnualLeaveWindow::AnnualLeaveWindow(const char *title, AbstractGroup<Worker *> *eventInvoker,
                                     AbstractEntityWindow<Worker *>::Type type,Worker *entity)
        : AbstractEntityWindow(525, 185, title, eventInvoker, type, entity) {
    this->begin();
    startDate = new Fl_Input(20,35,235,50);
    startDate->copy_label("Start Date:");
    startDate->align(FL_ALIGN_TOP);
    endDate = new Fl_Input(270,35,235,50);
    endDate->copy_label("End Date:");
    endDate->align(FL_ALIGN_TOP);

    if (entity->getAnnualLeave()->getCurrentDays() == 0){
        startDate->value("dd/mm/yyyy");
        endDate->value("dd/mm/yyyy");
    }else {
        fillOutInputs();
    }

    this->end();
}

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
    this->startDate->value(this->entity->getAnnualLeaveValue(AnnualLeave::Start).c_str());
    this->endDate->value(this->entity->getAnnualLeaveValue(AnnualLeave::End).c_str());
}
