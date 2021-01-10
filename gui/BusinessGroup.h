#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESSGROUP_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESSGROUP_H

#include "AbstractGroup.h"

class BusinessGroup : AbstractGroup<Business*>{
public:
    BusinessGroup(const char *string, const char *purpose, CRUD<Business *> *crud,
                  AbstractTableModel<Business *> *tableModel, Fl_Window *parent);

protected:
    void create() override;

    void modify() override;
};


#endif //CPP_UNIVERSITY_ASSIGMENT_BUSINESSGROUP_H
