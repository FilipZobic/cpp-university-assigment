//
// Created by filipz on 1/12/21.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTDISPLAYMODEL_H
#define CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTDISPLAYMODEL_H

#include <gui/AbstractDisplay/AbstractNavigationDisplayModel.h>
#include <model/Department.h>

class DepartmentDisplayModel : public AbstractNavigationDisplayModel<Department*> {
public:
    DepartmentDisplayModel(Department *currentEntity, vector<Department*> *entities);

private:
    Fl_Group *createDetailsDisplay() override;

    void updateDetailDisplay() override;

    string getMainDisplayText() override;
};


#endif //CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTDISPLAYMODEL_H
