#include <model/Business.h>
#include "NavigationDisplay.h"

template <typename T>
NavigationDisplay<T>::NavigationDisplay(AbstractNavigationDisplayModel<T> *model) : Fl_Group(355, 0, 745, 125, "Navigator"), model(model) {
    this->begin();

    prevBtn = new Fl_Button(363, 27, 70, 40,"@<-");
    prevBtn->align(FL_ALIGN_CENTER);
    nextBtn = new Fl_Button(665, 27, 70, 40,"@->");
    nextBtn->align(FL_ALIGN_CENTER);

    // render out put funkcija koja menja vrednosti na osnovu njega
    currentEntityNameDisplay = new Fl_Output(440, 26, 220, 40);
    currentEntityNameDisplay->value(this->model->getMainDisplayText().c_str());
    currentEntityNameDisplay->align(FL_ALIGN_TOP);
    currentEntityNameDisplay->copy_label(this->model->getQueueDisplayText().c_str());
    currentEntityNameDisplay->color();

    if (model->canDecreaseIndex()){

    }
    currentEntityNameDisplay->labelcolor(FL_BLUE);
    currentEntityNameDisplay->labelsize(20);

    this->end();
    this->show();
}

template<typename T>
void *NavigationDisplay<T>::createDetailsDisplay() {
    this->begin();
    this->detailsDisplay = this->model->createDetailsDisplay();
    this->end();
}

template class NavigationDisplay<Business*>;
template class NavigationDisplay<Department*>;
template class NavigationDisplay<Worker*>;