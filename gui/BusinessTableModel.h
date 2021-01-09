//
// Created by filipz on 1/8/21.
//
#include <string>
#include <vector>
#include <model/Business.h>

#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESSTABLEMODEL_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESSTABLEMODEL_H

using namespace std;

class BusinessTableModel {

private:
    int nuColumns;
    vector<Business*> *entities;

public:

    BusinessTableModel(vector<Business *> *entities) : nuColumns(5), entities(entities) {}

    string getColumnHeader(int y) {
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
    };
    string getRowHeader(int x) {
        return to_string(x);
    };
    string getCellValue(int x, int y){
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
    };

    /*Business* getCellEntity(int x){

    };

    vector<Business*> *getCellEnteties(int x_low, int x_high){

    }*/

    int getNumberOfRows(){
        return entities->size();
    };
    int getNumberOfColumns(){
        return nuColumns;
    };

    // dodam u crud model koji sve to radi saljemo mu crud iz kog on izvlaci to

    virtual Business* at(std::size_t index) {
        return this->entities->at(index);
    }
};


#endif //CPP_UNIVERSITY_ASSIGMENT_BUSINESSTABLEMODEL_H
