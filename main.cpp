#include <iostream>
#include <string>
#include <vector>

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
#include "./service/BusinessService.h"

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
    BusinessService businessService(fileNameBusiness,&DEPARTMENT_STORAGE_VECTOR,&service);

    service.getEntities()->at(0)->setName("Test");
    vector<string> replaceParams = {"1", "Marko", "Mihajilovic", "1/1/1999", "Driver", "6000.000000", "0652133910",
                                    "24|1/5/2010|25/5/2010", "B,C", "2"};
    crud.replaceEntity(replaceParams,2);
    crud.removeEntity(2,&businessService);

    cout << "All Workers" << endl;
    service.printArr();



    cout << "Department 1 workers" << endl;
    for(Worker* worker : (*businessService.getEntities()->at(0)->getWorkers())){
        cout << worker->Serialize() << endl;
    }

    return 0;
}