#include "CRUDDepartment.h"

CRUDDepartment::CRUDDepartment(Service<Department *> *service) : CRUD(service) {}

void CRUDDepartment::replaceEntity(Department *department) {

}

void CRUDDepartment::removeEntity(const long id) {

}


//calls the save method after finding correct department
//add fire
//add hire