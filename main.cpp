#include <iostream>
#include <string>
#include <vector>


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Float_Input.H>
#include <model/Business.h>
#include <service/BusinessMultiService.h>


#include "./model/Date.h"
#include "./model/Person.h"
#include "./model/Worker.h"
#include "./service/WorkerService.h"
#include "./logic/CRUD.h"
#include "./model/Warehouseman.h"
#include "./model/Clerk.h"
#include "./model/Driver.h"
#include "./service/WorkerService.h"
#include "./logic/CRUDWorker.h"

#include "./model/Department.h"
#include "./service/DepartmentMultiService.h"

// clear array at service that is vector
using namespace std;

//CRUD



int main() {

    // For Testing Creation

    Date birthDay(15,5,2000);
    Date birthDay2(15,5,2001);
    Date birthDay3(1,1,1999);

    // Warehouseman
    Date annualLeaveStart(1,5,2010);
    Date annualLeaveEnd(25,5,2010);
    Worker *warehouseman = new Warehouseman(1,"Petar","Markovic",birthDay,2000.00,"064553910");
    warehouseman->addOrReplaceAnnualLeave(annualLeaveStart,annualLeaveEnd);

    // Clerk
    Worker *clerk = new Clerk(32,"Zoran","Petrovic",birthDay2,2660.00,"0645213910","Register number 5, 55$ inside");

    //Driver
    vector<string> adc;
    vector<string> abc = {"B","C"};
    Worker *driver = new Driver(3,"Nikola","Vlasic",birthDay3,6000.00,"0652133910",2,abc);



    // Program Start
    // Init services
    vector<Worker*> WORKER_STORAGE_VECTOR;
    string filenameWorker = "Workers.csv";
    WorkerService workerService(filenameWorker, &WORKER_STORAGE_VECTOR);

    vector<Department*> DEPARTMENT_STORAGE_VECTOR;
    string filenameDepartment = "Department.csv";
    DepartmentMultiService departmentService(filenameDepartment, &DEPARTMENT_STORAGE_VECTOR, &workerService);

    vector<Business*> BUSINESS_STORAGE_VECTOR;
    string filenameBusiness = "Business.csv";
    BusinessMultiService businessService(filenameBusiness, &BUSINESS_STORAGE_VECTOR, &departmentService);
//    businessService.writeToFile();

    // Init CRUDs
    CRUDWorker crudWorker(&workerService, &departmentService);

    // Crud operations
    Department *dep1 = departmentService.getEntities()->at(0);
    crudWorker.setDepartment(dep1);
    crudWorker.removeEntity(29);
    crudWorker.replaceEntity(clerk);
//    dep1->setBoss(clerk); // ovo ce biti u crudDepartment od postojecih zaposlenih radnika kako bi pozvali write


    cout << "All Workers" << endl;
    workerService.printArr();

    cout << "Department 1 workers" << endl;
    for(Worker* worker : (*departmentService.getEntities()->at(0)->getWorkers())){
        cout << worker->Serialize() << endl;
    }

    // Checking

    cout << "Checking Business" << endl;
    cout << businessService.getEntities()->at(0)->Serialize() << endl;
    cout << businessService.getEntities()->at(1)->Serialize() << endl;
    cout << "Checking departments" << endl;
    cout << departmentService.getEntities()->at(0)->Serialize() << endl;
    cout << departmentService.getEntities()->at(1)->Serialize() << endl;
    cout << departmentService.getEntities()->at(2)->Serialize() << endl;

    // Gui
    Fl_Window *window = new Fl_Window(1200, 700);

    Fl_Box *label = new Fl_Box(500,0,200,100);
    label->label("WORKERS");
    label->labelsize(30);
    label->labelcolor(FL_BLACK);
    label->color(FL_BLUE);

    window->resizable();

    window->end();
    window->show();

    return Fl::run();
}