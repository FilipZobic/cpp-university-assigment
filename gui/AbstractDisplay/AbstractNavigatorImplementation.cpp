#include "AbstractNavigatorImplementation.h"
//Business, Department
template <typename T>
AbstractNavigatorImplementation<T>::AbstractNavigatorImplementation(){

}

template <typename T>
void AbstractNavigatorImplementation<T>::navigatorNextHandler(Fl_Widget *widget, void *data) {
    auto navigator = (AbstractNavigatorImplementation<T>*)data;
    navigator->navigatorNext();
}

template<typename T>
void AbstractNavigatorImplementation<T>::navigatorPreviousHandler(Fl_Widget *widget, void *data) {
    auto navigator = (AbstractNavigatorImplementation<T>*)data;
    navigator->navigatorPrevious();
}

template<typename T>
void AbstractNavigatorImplementation<T>::connectButtons(NavigationDisplay<T> *display) {

    display->getPrevBtn()->callback(this->navigatorPreviousHandler, this);
    display->getNextBtn()->callback(this->navigatorNextHandler, this);
}

template<typename T>
NavigationDisplay<T> *AbstractNavigatorImplementation<T>::getDisplay() const {
    return display;
}

template<typename T>
void AbstractNavigatorImplementation<T>::setDisplay(NavigationDisplay<T> *display) {
    AbstractNavigatorImplementation::display = display;
}

template class AbstractNavigatorImplementation<Business*>;
template class AbstractNavigatorImplementation<Department*>;
