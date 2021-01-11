#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <model/Business.h>
#include <service/BusinessMultiService.h>
#include <logic/CRUDDepartment.h>
#include <logic/CRUDBusiness.h>
#include <gui/MainWindow.h>
#include "./logic/CRUDWorker.h"

int main() {

    // Program Start
    // Init services
    vector<Worker*> WORKER_STORAGE_VECTOR;
    WorkerService workerService("Workers.csv", &WORKER_STORAGE_VECTOR);

    vector<Department*> DEPARTMENT_STORAGE_VECTOR;
    DepartmentMultiService departmentService("Department.csv", &DEPARTMENT_STORAGE_VECTOR, &workerService);

    vector<Business*> BUSINESS_STORAGE_VECTOR;
    BusinessMultiService businessService("Business.csv", &BUSINESS_STORAGE_VECTOR, &departmentService);

    // Init CRUDs
    CRUDWorker crudWorker(&workerService, &departmentService);
    CRUDDepartment crudDepartment(&departmentService,&workerService,&businessService);
    CRUDBusiness crudBusiness(&businessService, &crudDepartment);

    Fl_Window *window = new Fl_Window(300, 200,1100, 458);

    window->resizable();

    MainWindow mainWindow("Main window", &crudBusiness, &crudDepartment, &crudWorker);


    window->end();
    window->show();

    return Fl::run();
}