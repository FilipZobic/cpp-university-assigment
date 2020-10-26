#include <iostream>
#include <string>
#include <vector>

#include "./model/Date.h"
#include "./model/Person.h"
#include "./model/Worker.h"
#include "./service/WorkerService.h"
#include "./model/Warehouseman.h"
#include "./model/Clerk.h"
#include "./model/Driver.h"
#include "./service/WorkerService.h"

// clear array at service that is vector
using namespace std;

int main() {

    //Creating dates
    Date annualLeaveStart(20,2,2010);
    Date annualLeaveEnd(14,3,2010);

    Date annualLeaveStart1(1,5,2010);
    Date annualLeaveEnd1(25,5,2010);

    Date birthDay(15,5,2000);

    Date birthDay2(15,5,2001);

    Date birthDay3(1,1,1999);

    //Creating 3 types of workers
        //Warehouseman
            Worker *warehouseman = new Warehouseman(1,"Petar","Markovic",birthDay,2000.00,"064553910");
            warehouseman->addOrReplaceAnnualLeave(annualLeaveStart,annualLeaveEnd);
        //Clerk
            Worker *clerk = new Clerk(2,"Zoran","Petrovic",birthDay2,2660.00,"0645213910","Register number 5, 55$ inside");
        //Driver
            vector<string> adc;
            vector<string> abc = {"B","C"};
            Worker *driver = new Driver(3,"Nikola","Vlasic",birthDay3,6000.00,"0652133910",2,abc);
            driver->addOrReplaceAnnualLeave(annualLeaveStart1,annualLeaveEnd1);

    //Creating service and reading data
    vector<Worker*> WORKER_STORAGE_VECTOR; // njega menjam sa CRUD tj posaljem ga u CRUD pa pozovemo servis samo da snimi samog sebe
    string filename = "Workers.csv";
    WorkerService service(filename,&WORKER_STORAGE_VECTOR);

    //Adding workers to storage
//    WORKER_STORAGE_VECTOR.push_back(driver);
//    WORKER_STORAGE_VECTOR.push_back(clerk);
//    WORKER_STORAGE_VECTOR.push_back(warehouseman);

    //Testing storage
    cout << "Array Main ======" << endl;
    for (Worker* i : WORKER_STORAGE_VECTOR) {
        cout << i->Serialize() << endl;
    }
    cout << "Array Service ======" << endl;
    service.printArr();

    //Service Saving
    service.writeToFile();

    return 0;
}