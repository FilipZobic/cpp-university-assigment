#include "Department.h"
#include "../util/Util.h"
#include "iostream"

Department::Department(long id, string name, Worker *boss,vector<Worker *>* workers) : id(id), boss(boss), workers(workers), name(name) {}
Department::Department(long id, Worker *boss,vector<Worker *>* workers) : id(id), boss(boss), workers(workers) {}
Department::Department(long id,vector<Worker *>* workers) : id(id), workers(workers) {
    this->boss = nullptr;
}
Department::Department(long id):id(id) {
    this->workers = new vector<Worker*>;
    this->boss = nullptr;
}


Department::Department(const string &name) : name(name) {
    this->workers = new vector<Worker*>;
    this->boss = nullptr;
}

Department::Department() {
    this->workers = new vector<Worker*>;
    this->boss = nullptr;
}
Department::~Department() {
    this->workers->erase(this->workers->begin(),this->workers->end());
    delete workers;
    this->boss = nullptr;
    delete this->boss;
}

void Department::hireWorker(Worker *worker) {
    long index = cuaUtil::findIndex<Worker*>(worker->getId(), this->workers);
    if (index == -1){
        workers->push_back(worker);
    }else {
        throw logic_error("Workers is already working here");
    }
}

void Department::fireWorker(const long &id) {
    long index = cuaUtil::findIndex<Worker*>(id, this->workers);
    if (index != -1){
        workers->erase(workers->begin()+index);
        if (boss != nullptr && boss->getId() == id) {
            this->setBoss(nullptr);
        }
    }else {
        cout << "Worker is not working here" << endl;
    }
}

void Department::replaceWorker(Worker *worker) {
    long index = cuaUtil::findIndex<Worker*>(worker->getId(), this->workers);
    if (index != -1){
        if (boss != nullptr && boss->getId() == worker->getId()) {
            this->setBoss(worker);
        }
        workers->at(index) = worker;
    }else {
        throw logic_error("Worker is not working here");
    }
};

string Department::Serialize() {
    string people = "";
    if (!workers->empty()){
        for (Worker *ref : (*workers)) { //ovde mozda pokazivac pokazivaca
            people += to_string(ref->getId()) + ",";
        }
        people.erase(people.size()-1,people.size());
    } else{
        people += "-1";
    }

    long bossId = -1;
    if (this->boss != nullptr) {
        bossId = this->boss->getId();
    }

    return  to_string(this->id) + sep + this->name + sep + to_string(bossId) + sep + people;
}


void Department::Parse(vector<string> params) {
    this->name = params.at(1);
    this->id = stol(params.at(0));
}

long Department::getId() const {
    return id;
}

void Department::setId(long id) {
    Department::id = id;
}

Worker *Department::getBoss() const {
    return boss;
}

void Department::setBoss(Worker *boss) {
    this->boss = boss;
}

vector<Worker *> *Department::getWorkers() const {
    return workers;
}

void Department::setWorkers(vector<Worker *> *workers) {
    Department::workers = workers;
}

void Department::operator<<(Worker *worker) {

    cuaUtil::vectorInstanceCheck<Worker>(worker,this->workers);

    this->workers->push_back(worker);
}

const string &Department::getName() const {
    return name;
}

void Department::setName(const string &name) {
    Department::name = name;
}

int Department::getNumberOfWorkers() {
    return this->workers->size();
}

int Department::getNumberOfSpecificWorker(Department::Type type) {
    int size = 0;
    string toSearchFor = "";
    if (type == Warehouseman) {
        toSearchFor = "Warehouseman";
    } else if (type == Clerk) {
        toSearchFor = "Clerk";
    } else if (type == Driver) {
        toSearchFor = "Driver";
    }

    for (Worker *worker : *this->workers) {
        if (worker->getType() == toSearchFor) size++;
    }

    return size;
}

string Department::getBossName() {
    if (nullptr == this->boss){
        return "No Boss";
    }else {
        return this->boss->getFullName();
    }
}

double Department::getSpending() {
    double sum = 0;
    for (Worker *worker : *this->workers){
        sum += worker->getSalary();
    }
    return sum;
}

void *Department::getBusiness() const {
    return business;
}

void Department::setBusiness(void *business) {
    this->business = business;
}
