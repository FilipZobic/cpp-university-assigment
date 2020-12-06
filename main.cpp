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



    //Creating worker service and reading data and worker CRUD
    vector<Worker*> WORKER_STORAGE_VECTOR; // njega menjam sa CRUD tj posaljem ga u CRUD pa pozovemo servis samo da snimi samog sebe
    string filename = "Workers.csv";
    WorkerService service(filename,&WORKER_STORAGE_VECTOR);
    CRUDWorker crud(&service);

    //Creating business service and reading data and worker CRUD
    vector<Department*> DEPARTMENT_STORAGE_VECTOR; // njega menjam sa CRUD tj posaljem ga u CRUD pa pozovemo servis samo da snimi samog sebe
    string fileNameBusiness = "Department.csv";
    DepartmentMultiService departmentService(fileNameBusiness, &DEPARTMENT_STORAGE_VECTOR, &service);

//    service.getEntities()->at(0)->setName("Test");
//    vector<string> replaceParams = {"1", "Marko", "Lahovic", "1/1/1999", "Driver", "6000.000000", "0652133910",
//                                    "24|1/5/2010|25/5/2010", "B,C", "2"};
//    crud.replaceEntity(replaceParams,1,&departmentService);
    crud.removeEntity(2,&departmentService);

//    vector<string> newParams = {"1", "Bojan", "Zoranovic", "1/1/1999", "Driver", "6000.000000", "0652133910",
//                                    "24|1/5/2010|25/5/2010", "B,C", "2"};
//    crud.createEntity(newParams);

    cout << "All Workers" << endl;
    service.printArr();

    cout << "Department 1 workers" << endl;
    for(Worker* worker : (*departmentService.getEntities()->at(0)->getWorkers())){
        cout << worker->Serialize() << endl;
    }

    Fl_Window *window = new Fl_Window(1200, 700);

    Fl_Box *label = new Fl_Box(500,0,200,100);
    label->label("WORKERS");
    label->labelsize(30);
    label->labelcolor(FL_BLACK);
    label->color(FL_BLUE);


    // Dodaj Service Dodaj Crud zapamti department can only belong to one business and worker can only belong to one department
    window->resizable();

//    Business *business = new Business("EPS",1111,9090);
//    Business *business2 = new Business("DELL",9024,7000);
//    (*business) << DEPARTMENT_STORAGE_VECTOR.at(2);
//    (*business) << DEPARTMENT_STORAGE_VECTOR.at(1);
//    (*business2) << DEPARTMENT_STORAGE_VECTOR.at(0);
//    cout << business->Serialize();
//    cout << business2->Serialize();

    vector<Business*> BUSINESS_STORAGE_VECTOR;
//    BUSINESS_STORAGE_VECTOR.push_back(business);
//    BUSINESS_STORAGE_VECTOR.push_back(business2);
    string businessFilename = "Business.csv";
    BusinessMultiService businessService(businessFilename, &BUSINESS_STORAGE_VECTOR, &departmentService);
    businessService.writeToFile();
//    CRUDBusiness businessCRUD(&businessService);

    window->end();
    window->show();

    cout << "Checking Business" << endl;
    cout << businessService.getEntities()->at(0)->Serialize() << endl;
    cout << businessService.getEntities()->at(1)->Serialize() << endl;
    cout << "Checking departments" << endl;
    cout << departmentService.getEntities()->at(0)->Serialize() << endl;
    cout << departmentService.getEntities()->at(1)->Serialize() << endl;
    cout << departmentService.getEntities()->at(2)->Serialize() << endl;
    return Fl::run();
}