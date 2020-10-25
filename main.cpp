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

// clear array at service that is vector
using namespace std;

int main() {

    Date date(28,2,2010);

    cout << date.toString() << endl;

    Worker *person = new Warehouseman(1,"Petar","Markovic",date,2000.00,"064553910");

    Date dateA(20,2,2010);
    Date dateB(14,3,2010);

    cout << dateA.getSumOfDays() << " " << dateB.getSumOfDays() << " " << (dateB.getSumOfDays()-dateA.getSumOfDays()) << endl;
    person->addOrReplaceAnnualLeave(dateA,dateB);

    string toSend = person->Serialize();
    cout << toSend << endl;

    Worker *person1 = new Warehouseman();
    WorkerService workerService;
    workerService.ParseWorker(toSend,person1);

    string toReceive = person1->Serialize();
    cout << toReceive << endl;

    cout << to_string(date.getSumOfDays()) << endl;

    Worker *clerk = new Clerk(2,"Zoran","Petrovic",date,2660.00,"0645213910","Register number 5, 55$ inside");
    string toSendClerk = clerk->Serialize();
    cout << toSendClerk << endl;
    Worker *clerk2 = new Clerk();
    workerService.ParseWorker(toSendClerk,clerk2);
    string toReciveClerk = clerk2->Serialize();
    cout << toReciveClerk << endl;
//drivers
    vector<string> adc;
    vector<string> abc = {"B","C"};
    Worker *driver = new Driver(3,"Nikola","Vlasic",date,6000.00,"0652133910",2,abc);
    Date dateC(1,5,2010);
    Date dateD(25,5,2010);
    driver->addOrReplaceAnnualLeave(dateC,dateD);
    string toSendDriver = driver->Serialize();
    cout << toSendDriver << endl;
    Worker *driver1 = new Driver();
    workerService.ParseWorker(toSendDriver,driver1);
    cout << driver1->Serialize() << endl;

    return 0;
}