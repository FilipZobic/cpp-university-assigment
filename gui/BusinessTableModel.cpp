#include "BusinessTableModel.h"

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
        default:
            throw logic_error("Wrong value passed");
    }
}