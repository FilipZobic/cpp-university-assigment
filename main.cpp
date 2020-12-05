#include <iostream>
#include <string>
#include <vector>


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Float_Input.H>


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
#include "./service/DepartmentService.h"

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
    DepartmentService businessService(fileNameBusiness, &DEPARTMENT_STORAGE_VECTOR, &service);

//    service.getEntities()->at(0)->setName("Test");
//    vector<string> replaceParams = {"1", "Marko", "Lahovic", "1/1/1999", "Driver", "6000.000000", "0652133910",
//                                    "24|1/5/2010|25/5/2010", "B,C", "2"};
//    crud.replaceEntity(replaceParams,1,&businessService);
    crud.removeEntity(2,&businessService);

//    vector<string> newParams = {"1", "Bojan", "Zoranovic", "1/1/1999", "Driver", "6000.000000", "0652133910",
//                                    "24|1/5/2010|25/5/2010", "B,C", "2"};
//    crud.createEntity(newParams);

    cout << "All Workers" << endl;
    service.printArr();

    cout << "Department 1 workers" << endl;
    for(Worker* worker : (*businessService.getEntities()->at(0)->getWorkers())){
        cout << worker->Serialize() << endl;
    }

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