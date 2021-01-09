#include <string>
#include <vector>
#include <model/Business.h>


#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESSTABLEMODEL_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESSTABLEMODEL_H

#include "AbstractTableModel.h"

using namespace std;

class BusinessTableModel : public AbstractTableModel<Business*> {

public:

    BusinessTableModel(vector<Business*> *entities) : AbstractTableModel(5, entities) {}

    string getColumnHeader(int y) override;

    string getCellValue(int x, int y) override;
};

#endif