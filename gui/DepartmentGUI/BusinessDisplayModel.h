#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESSDISPLAYMODEL_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESSDISPLAYMODEL_H

#include <gui/AbstractDisplay/AbstractNavigationDisplayModel.h>
#include <model/Business.h>

class BusinessDisplayModel : public AbstractNavigationDisplayModel<Business*> {
protected:
    Fl_Output *a1;
    Fl_Output *a2;
    Fl_Output *a3;
    Fl_Output *a5;
    Fl_Output *a6;
    Fl_Output *a7;
public:
    BusinessDisplayModel(Business *currentEntity, vector<Business*> *entities);

    Fl_Group *createDetailsDisplay() override;

    string getMainDisplayText() override;

    void updateDetailDisplay() override;
};


#endif