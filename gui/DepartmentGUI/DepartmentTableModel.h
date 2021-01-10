#ifndef CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTTABLEMODEL_H
#define CPP_UNIVERSITY_ASSIGMENT_DEPARTMENTTABLEMODEL_H


#include <model/Department.h>

#include <gui/AbstractTableModel.h>

class DepartmentTableModel : public AbstractTableModel<Department*> {
public:
    DepartmentTableModel(vector<Department*> *entities);

    string getColumnHeader(int y) override;

    string getCellValue(int x, int y) override;
};


#endif
