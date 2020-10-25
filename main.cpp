#include <iostream>
#include <string>
#include <vector>

#include "./model/Date.h"
#include "./model/Person.h"
#include "./model/Worker.h"
#include "./service/WorkerService.h"

// clear array at service that is vector
using namespace std;

int main() {

    Date date(28,2,2010);

    cout << date.toString() << endl;

    Worker *person = new Worker(1,"Petar","Markovic",date,"Magacioner",2000.00,"064553910");

    Date dateA(20,2,2010);
    Date dateB(14,3,2010);

    cout << dateA.getSumOfDays() << " " << dateB.getSumOfDays() << " " << (dateB.getSumOfDays()-dateA.getSumOfDays()) << endl;
    person->addOrReplaceAnnualLeave(dateA,dateB);

    string toSend = person->Serialize();
    cout << toSend << endl;

    Worker *person1 = new Worker();
    WorkerService workerService;
    workerService.ParseWorker(toSend,person1);

    string toReceive = person1->Serialize();
    cout << toReceive << endl;

    cout << to_string(date.getSumOfDays()) << endl;

    return 0;
}