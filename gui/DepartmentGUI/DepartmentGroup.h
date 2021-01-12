#ifndef CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTGROUP_H
#define CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTGROUP_H


#include <gui/AbstractGroup.h>
#include <gui/AbstractDisplay/AbstractNavigatorImplementation.h>

class DepartmentGroup : public AbstractGroup<Department*> , public AbstractNavigatorImplementation<Business*>{
public:
    DepartmentGroup(const char *string, const char *purpose, CRUD<Department *> *crud,
                    AbstractTableModel<Department *> *tableModel, Fl_Window *parent);

    void navigatorNext() override;

    void navigatorPrevious() override;

    void createNavigator() override;

    void updateCrudAndTableModel() override;


public:
    void create() override;

    void modify() override;
};


#endif
