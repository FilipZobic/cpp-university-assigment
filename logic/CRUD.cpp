//
// Created by filipz on 10/25/20.
//

#include "CRUD.h"
#include "../model/Worker.h"

template <typename T>
CRUD<T>::CRUD(Service<T> *service) : service(service) {}

template <typename T>

void CRUD<T>::addEntity(T entity) {
    vector<T> *entities = service->getEntities();
    entities->push_back(entity);
    service->setAmountOfItems(service->getAmountOfItems()+1); //id setujemo na object creation ovde ga povecaamo znaci ovde stoji sledeci koji ce se iskoristiti
    service->setLastUsedId(service->getLastUsedId()+1);
    service->writeToFile();
};




template class CRUD<Worker*>;