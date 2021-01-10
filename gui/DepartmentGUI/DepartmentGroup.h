#ifndef CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTGROUP_H
#define CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTGROUP_H


#include <gui/AbstractGroup.h>

class DepartmentGroup : public AbstractGroup<Department*> {
public:
    DepartmentGroup(const char *string, const char *purpose, CRUD<Department *> *crud,
                    AbstractTableModel<Department *> *tableModel, Fl_Window *parent);

protected:
public:
    void create() override;

    void modify() override;
};


#endif
