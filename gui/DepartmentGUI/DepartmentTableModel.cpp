//
// Created by filipz on 1/10/21.
//

#include "DepartmentTableModel.h"

DepartmentTableModel::DepartmentTableModel(vector<Department*> *entities) : AbstractTableModel(6,
                                                                                                    entities) {}

string DepartmentTableModel::getColumnHeader(int y) {
    switch (y) {
        case 0:
            return "Name";
        case 1:
            return "Boss";
        case 2:
            return "Nu. Workers";
        case 3:
            return "Nu. Warehousemen";
        case 4:
            return "Nu. Clerks";
        case 5:
            return "Nu. Drivers";
        default:
            throw logic_error("Wrong value passed");
    }
}

string DepartmentTableModel::getCellValue(int x, int y) {
    Department *department = entities->at(x);
    switch (y) {
        case 0:
            return department->getName();
        case 1:
            return department->getBossName();
        case 2:
            return to_string(department->getNumberOfWorkers());
        case 3:
            return to_string(department->getNumberOfSpecificWorker(Department::Warehouseman));
        case 4:
            return to_string(department->getNumberOfSpecificWorker(Department::Clerk));
        case 5:
            return to_string(department->getNumberOfSpecificWorker(Department::Driver));
        default:
            throw logic_error("Wrong value passed");
    }
}
