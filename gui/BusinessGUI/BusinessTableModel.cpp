#include "BusinessTableModel.h"
#include "util/Util.h"
BusinessTableModel::BusinessTableModel(vector<Business*> *entities) : AbstractTableModel(8, entities) {}

string BusinessTableModel::getColumnHeader(int y) {
    switch (y) {
        case 0:
            return "Name";
        case 1:
            return "Reg. Nu.";
        case 2:
            return "VAT";
        case 3:
            return "Nu. Dept.";
        case 4:
            return "Phone Nu.";
        case 5:
            return "Address";
        case 6:
            return "Nu. Workers";
        case 7:
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
            return business->getPhoneNumber();
        case 5:
            return business->getAddress();
        case 6:
            return to_string(business->getNumberOfWorkers());
        case 7:
            return cuaUtil::roundDouble(business->calculateSpending());
        default:
            throw logic_error("Wrong value passed");
    }
}