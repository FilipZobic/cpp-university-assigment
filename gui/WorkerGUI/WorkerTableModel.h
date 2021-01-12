//
// Created by filipz on 1/12/21.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_WORKERTABLEMODEL_H
#define CPP_UNIVERSITY_ASSIGMENT_WORKERTABLEMODEL_H


#include <model/Worker.h>
#include "gui/AbstractTable/AbstractTableModel.h"

class WorkerTableModel : public AbstractTableModel<Worker*> {
public:
    WorkerTableModel(vector<Worker*> *entities);

private:
    string getColumnHeader(int y) override;

    string getCellValue(int x, int y) override;
};


#endif //CPP_UNIVERSITY_ASSIGMENT_WORKERTABLEMODEL_H
