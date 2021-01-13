#include "WorkerTableModel.h"
#include "model/Clerk.h"
#include "model/Driver.h"
#include "util/Util.h"

WorkerTableModel::WorkerTableModel(vector<Worker*> *entities) : AbstractTableModel(12, entities) {}

string WorkerTableModel::getColumnHeader(int y) {
    switch (y) {
        case 0:
            return "Name";
        case 1:
            return "Surname";
        case 2:
            return "Birth Day";
        case 3:
            return "Salary";
        case 4:
            return "Phone Nu.";
        case 5:
            return "L. Length";
        case 6:
            return "L. Start";
        case 7:
            return "L. End";
        case 8:
            return "Type";
        case 9:
            return "Reg. Info";
        case 10:
            return "Nu. Infra.";
        case 11:
            return "Licenses";
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
            return cuaUtil::roundDouble(this->entities->at(x)->getSalary());
        case 4:
            return this->entities->at(x)->getMobileNumber();
        case 5:
            if (this->entities->at(x)->getAnnualLeave()->getCurrentDays() != 0){
                return to_string(this->entities->at(x)->getAnnualLeave()->getCurrentDays());
            }
            return "";
        case 6:
            return this->entities->at(x)->getAnnualLeaveValue(AnnualLeave::Start);
        case 7:
            return this->entities->at(x)->getAnnualLeaveValue(AnnualLeave::End);
        case 8:
            return this->entities->at(x)->getType();
        case 9:
            if (this->entities->at(x)->getType() == "Clerk"){
                Clerk *clerk = (Clerk*)this->entities->at(x);
                return clerk->getCashRegisterInfo();
            } else{
                return "";
            }
        case 10:
            if (this->entities->at(x)->getType() == "Driver"){
                Driver *driver = (Driver*)this->entities->at(x);
                return to_string(driver->getNumTrafficInfractions());
            } else{
                return "";
            }
        case 11:
            if (this->entities->at(x)->getType() == "Driver"){
                Driver *driver = (Driver*)this->entities->at(x);
                return driver->drivingCategoriesToString();
            } else{
                return "";
            }
    }
}
