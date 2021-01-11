//
// Created by filipz on 1/10/21.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_NAVIGATIONDISPLAY_H
#define CPP_UNIVERSITY_ASSIGMENT_NAVIGATIONDISPLAY_H


#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <vector>
#include "AbstractNavigationDisplayModel.h"
#include <Fl/Fl_Output.H>

using namespace std;

template <typename T>
class NavigationDisplay : public Fl_Group {
protected:
    AbstractNavigationDisplayModel<T> *model;
    Fl_Button *prevBtn;
    Fl_Button *nextBtn;
    Fl_Output *currentEntityNameDisplay;
    Fl_Group *detailsDisplay;

//connect it via setter in main window
public:
    NavigationDisplay(AbstractNavigationDisplayModel<T> *model);
    void *createDetailsDisplay();


};


#endif //CPP_UNIVERSITY_ASSIGMENT_NAVIGATIONDISPLAY_H
