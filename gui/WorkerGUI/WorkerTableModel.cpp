//
// Created by filipz on 1/12/21.
//

#include "WorkerTableModel.h"

WorkerTableModel::WorkerTableModel(vector<Worker*> *entities) : AbstractTableModel(5, entities) {}

string WorkerTableModel::getColumnHeader(int y) {
    switch (y) {
        case 0:
            return "Name";
        case 1:
            return "Surname";
        case 2:
            return "Birth Day";
        case 3:
            return "Type";
        case 4:
            return "Salary";
        default:
            throw logic_error("Wrong value passed");
    }
}

string WorkerTableModel::getCellValue(int x, int y) {
    switch (y) {
        case 0:
            return this->entities->at(x)->getName();
        case 1:
            return this->entities->at(x)->getSurname();
        case 2:
            return this->entities->at(x)->getBirthday().toString();
        case 3:
            return this->entities->at(x)->getType();
        case 4:
            return to_string(this->entities->at(x)->getSalary());
        default:
            throw logic_error("Wrong value passed");
    }
}
