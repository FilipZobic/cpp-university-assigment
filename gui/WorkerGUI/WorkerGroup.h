#ifndef CPP_UNIVERSITY_ASSIGMENT_WORKERGROUP_H
#define CPP_UNIVERSITY_ASSIGMENT_WORKERGROUP_H


#include <model/Worker.h>
#include <gui/AbstractGroup.h>
#include <gui/AbstractDisplay/AbstractNavigatorImplementation.h>

class WorkerGroup  : public AbstractGroup<Worker*>, public AbstractNavigatorImplementation<Department*> {
private:
    Fl_Button *annualLeaveBtn;
    Fl_Button *assignBoss;
public:
    WorkerGroup(const char *string, const char *purpose, CRUD<Worker *> *crud, AbstractTableModel<Worker *> *tableModel,
                Fl_Window *parent, vector<Department*>* businessDepartments);

    void create() override;

    void modify() override;

    void navigatorNext() override;

    void navigatorPrevious() override;

    void createNavigator() override;

    void updateCrudAndTableModel() override;

    void turnOnButtons(SwitchType switchType) override;

    void turnOffButtons(SwitchType switchType) override;

    static void annualLeaveEventHandler(Fl_Widget *widget, void *data);
};

#endif
