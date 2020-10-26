//
// Created by filipz on 10/25/20.
//

#include "CRUD.h"
#include <stdexcept>
#include "../model/Worker.h"

template <typename T>
CRUD<T>::CRUD(Service<T> *service) : service(service) {}

template <typename T>

void CRUD<T>::addEntity(T entity) const {
    vector<T> *entities = service->getEntities();
    entities->push_back(entity);
    service->setAmountOfItems(service->getAmountOfItems()+1); //id setujemo na object creation ovde ga povecaamo znaci ovde stoji sledeci koji ce se iskoristiti
    service->setLastUsedId(service->getLastUsedId()+1);
    service->writeToFile();
};

template <typename T>
void CRUD<T>::deleteEntity(long index) const { // we send id to parent class that will overwrite this method then we send index of the element


    vector<T> *entities = service->getEntities();
    cout << "SIZE===" + to_string(entities->size()) << endl;
    if (index>=entities->size()||0>index){
        throw out_of_range("Index out of range in CRUD deleteEntity()");
    }
    delete entities->at(index);
    entities->erase(entities->begin()+index,entities->begin()+index+1);

    service->setAmountOfItems(service->getAmountOfItems()-1);


    service->writeToFile();
}




template class CRUD<Worker*>;