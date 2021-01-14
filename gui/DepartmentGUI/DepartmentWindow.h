#ifndef CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTWINDOW_H
#define CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTWINDOW_H


#include <gui/AbstractEntityWindow.h>

class DepartmentWindow : public AbstractEntityWindow<Department*> {
public:
    DepartmentWindow(const char *title, AbstractGroup<Department *> *eventInvoker, Type type = New,
                      Department *entity = nullptr);

    virtual ~DepartmentWindow();

    void createEventHandler() override;

    void inputValidationCheck() override;

    void replaceEventHandler() override;

    Department *newEntity() override;

    void fillOutInputs() override;

protected:
    Fl_Input *name;
};

#endif
