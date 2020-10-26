//
// Created by filipz on 10/25/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_CRUD_H
#define CPP_UNIVERSITY_ASSIGMENT_CRUD_H

#include "../service/Service.h"

template <typename T>
class CRUD {
protected:
    Service<T>* service; //saljemo worker service ovde
public:
    void addEntity(T entity); //calls writeToFile after push_back array and ++numOfLements as well lastUsedId maybe add star //this entities shared vector of
    CRUD<T>(Service<T> *service);

//    void deleteEntity(long id); //calls writeToFile after deleting vector element and erasing array position and --numberOfElementsinService
//    void replaceEntity(long id); //calls writeToFile after modifying the vector element attributes
//    void readEntities();//calls service parseAllEntities for same array
//
//    virtual void createEntity(vector<string>params) = 0; // after redifiniton in their crud service calls add entity
};

/*
 * crud operacija sadrzi promenljivu tipa servis
 * servis se poziva na kraju svake operacije
 * read poziva read servis i to samo prilikom inicilizacije programa gde ucitava sve podatka u vector na koj pokazuje i servis
 * delete brisemo preko id broja smanjujemo ukupan broj elemenata brisem poziciju u arrayu ali pre toga ga izbacujemo iz odeljenja ako je u jednom snimimo fajl preko servicesa
 * replace preko pointera promenimo polja koja se menjaju i snimimo fajl preko servisa
 * create povecam id povecam broj elemenata stavim na kraj vectora i snimim preko servisa*/

#endif //CPP_UNIVERSITY_ASSIGMENT_CRUD_H
