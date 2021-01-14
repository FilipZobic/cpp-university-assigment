#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESSGROUP_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESSGROUP_H

#include "gui/AbstractGroup.h"

class BusinessGroup : public AbstractGroup<Business*>{
public:
    BusinessGroup(const char *string, const char *purpose, CRUD<Business *> *crud,
                  AbstractTableModel<Business *> *tableModel, Fl_Window *parent);

    virtual ~BusinessGroup();

protected:
    void create() override;

    void modify() override;
};

#endif