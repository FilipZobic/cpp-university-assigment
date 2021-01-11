#include <string>
#include <vector>
#include <model/Business.h>


#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESSTABLEMODEL_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESSTABLEMODEL_H

#include "gui/AbstractTable/AbstractTableModel.h"

using namespace std;

class BusinessTableModel : public AbstractTableModel<Business*> {

public:

    BusinessTableModel(vector<Business*> *entities);

    string getColumnHeader(int y) override;

    string getCellValue(int x, int y) override;
};

#endif