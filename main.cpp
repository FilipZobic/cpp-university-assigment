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

    Person *person = new Worker(1,"Petar","Markovic",date,"Magacioner",2000.00,"064553910");
    string toSend = person->Serialize();
    cout << toSend << endl;

    Worker *person1 = new Worker();
    WorkerService workerService;
    workerService.ParseWorker(toSend,person1);

    string toRecive = person1->Serialize();
    cout << toRecive << endl;

    cout << to_string(date.getSumOfDays()) << endl;

    return 0;
}