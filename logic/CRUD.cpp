#include "CRUD.h"
#include <stdexcept>
#include <model/Business.h>
#include "../model/Department.h"

template <typename T>
CRUD<T>::CRUD(Service<T> *service) : service(service) {}

template <typename T>

void CRUD<T>::addEntity(const T entity) const {
    vector<T> *entities = service->getEntities();
    entities->push_back(entity);
    service->setAmountOfItems(service->getAmountOfItems()+1); //id setujemo na object creation ovde ga povecaamo znaci ovde stoji sledeci koji ce se iskoristiti
    service->setLastUsedId(service->getLastUsedId()+1);
    service->writeToFile();
};

template <typename T>
void CRUD<T>::deleteEntity(const long index) const { // we send id to parent class that will overwrite this method then we send index of the element

    service->clearMemory(index);
}
template <typename T>
void CRUD<T>::replace(const long index,T entity) { // we send id to parent class that will overwrite this method then we send index of the element


    vector<T> *entities = service->getEntities();
    cout << "SIZE===" + to_string(entities->size()) << endl;
    if (index>=entities->size()||0>index){
        throw out_of_range("Index out of range in CRUD deleteEntity()");
    }
    delete entities->at(index);
    entities->at(index) = entity;
    service->writeToFile();
}

template <typename T>
void CRUD<T>::readEntities(){
    vector<T> *entities = service->getEntities();
    for (T entity : (*entities)) {
        delete entity;
    }
    entities->erase(entities->begin(),entities->end());
    service->parseAllEntities();
}

template<typename T>
Service<T> *const CRUD<T>::getService() const {
    return service;
}

template class CRUD<Worker*>;
template class CRUD<Department*>;
template class CRUD<Business*>;