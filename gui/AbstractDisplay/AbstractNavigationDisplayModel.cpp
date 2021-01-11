#include <model/Business.h>
#include "AbstractNavigationDisplayModel.h"

template<typename T>
AbstractNavigationDisplayModel<T>::AbstractNavigationDisplayModel(T currentEntity, vector<T> *entities):currentEntity(
        currentEntity), entities(entities) {
    for(T e : *entities) {
        if (e == currentEntity) break;
        currentIndex++;
    }
}

template<typename T>
string AbstractNavigationDisplayModel<T>::getQueueDisplayText() {
    return to_string(currentIndex+1) + "/" + to_string(this->size());
}

template<typename T>
int AbstractNavigationDisplayModel<T>::getCurrentIndex() {
    return currentIndex;
}

template<typename T>
int AbstractNavigationDisplayModel<T>::size() {
    return this->entities->size();
}

template<typename T>
bool AbstractNavigationDisplayModel<T>::canIncreaseIndex() {
    return this->currentIndex + 1 < this->size();
}

template<typename T>
bool AbstractNavigationDisplayModel<T>::canDecreaseIndex() {
    return this->currentIndex - 1 != 0;
}

template<typename T>
void AbstractNavigationDisplayModel<T>::nextEntity() {
    this->currentIndex += 1;
    this->currentEntity = this->entities->at(this->currentIndex);
}

template<typename T>
void AbstractNavigationDisplayModel<T>::prevEntity() {
    this->currentIndex -= 1;
    this->currentEntity = this->entities->at(this->currentIndex);
}


template class AbstractNavigationDisplayModel<Business*>;
template class AbstractNavigationDisplayModel<Department*>;
template class AbstractNavigationDisplayModel<Worker*>;