#include "BusinessTableModel.h"
#include "util/Util.h"
BusinessTableModel::BusinessTableModel(vector<Business*> *entities) : AbstractTableModel(6, entities) {}

string BusinessTableModel::getColumnHeader(int y) {
    switch (y) {
        case 0:
            return "Name";
        case 1:
            return "Registration Nu.";
        case 2:
            return "VAT";
        case 3:
            return "Nu. Departments";
        case 4:
            return "Nu. Workers";
        case 5:
            return "Spending";
        default:
            throw logic_error("Wrong value passed");
    }
}

string BusinessTableModel::getCellValue(int x, int y) {
    Business *business = entities->at(x);
    switch (y) {
        case 0:
            return business->getName();
        case 1:
            return to_string(business->getId());
        case 2:
            return to_string(business->getVat());
        case 3:
            return to_string(business->getNumberOfDepartments());
        case 4:
            return to_string(business->getNumberOfWorkers());
        case 5:
            return cuaUtil::roundDouble(business->calculateSpending());
        default:
            throw logic_error("Wrong value passed");
    }
}