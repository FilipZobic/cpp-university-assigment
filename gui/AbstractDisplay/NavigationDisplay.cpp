#include <model/Business.h>
#include <gui/BusinessGUI/BusinessGroup.h>
#include "NavigationDisplay.h"

template <typename T>
NavigationDisplay<T>::NavigationDisplay(AbstractNavigationDisplayModel<T> *model) : Fl_Group(355, 0, 745, 125, "Navigator"), model(model){
    this->begin();

    prevBtn = new Fl_Button(363, 27, 70, 40,"@<-");
    prevBtn->align(FL_ALIGN_CENTER);
//    prevBtn->callback(this->prevEntity, this);
    nextBtn = new Fl_Button(665, 27, 70, 40,"@->");
    nextBtn->align(FL_ALIGN_CENTER);
//    nextBtn->callback(this->nextEntity, this);

    // render out put funkcija koja menja vrednosti na osnovu njega
    currentEntityNameDisplay = new Fl_Output(440, 26, 220, 40);
    currentEntityNameDisplay->align(FL_ALIGN_TOP);
    currentEntityNameDisplay->color();

    this->checkButtons();
    createDetailsDisplay();
    this->reRender();

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

template<typename T>
T NavigationDisplay<T>::nextEntity() {
    T entity = this->model->nextEntity();
    this->checkButtons();
    this->reRender();
    return entity;
}

template<typename T>
T NavigationDisplay<T>::prevEntity() {
    T entity = this->model->prevEntity();
    this->checkButtons();
    this->reRender();
    return entity;
}

template<typename T>
void NavigationDisplay<T>::checkButtons() {
    if (!this->model->canIncreaseIndex()){
        this->nextBtn->deactivate();
    }else {
        this->nextBtn->activate();
    }
    if (!this->model->canDecreaseIndex()){
        this->prevBtn->deactivate();
    }else {
        this->prevBtn->activate();
    }

}

template<typename T>
void NavigationDisplay<T>::reRender() {

    currentEntityNameDisplay->value(this->model->getMainDisplayText().c_str());
    currentEntityNameDisplay->copy_label(this->model->getQueueDisplayText().c_str());
    this->model->updateDetailDisplay();
}

template<typename T>
Fl_Button *NavigationDisplay<T>::getPrevBtn() const {
    return prevBtn;
}

template<typename T>
Fl_Button *NavigationDisplay<T>::getNextBtn() const {
    return nextBtn;
}

template class NavigationDisplay<Business*>;
template class NavigationDisplay<Department*>;
template class NavigationDisplay<Worker*>;