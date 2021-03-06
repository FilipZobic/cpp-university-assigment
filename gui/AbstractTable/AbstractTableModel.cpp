#include <model/Business.h>
#include "AbstractTableModel.h"

template<typename T>
AbstractTableModel<T>::AbstractTableModel(int nuColumns, vector<T> *entities):nuColumns(nuColumns),
                                                                              entities(entities) {}

template<typename T>
string AbstractTableModel<T>::getRowHeader(int x) {
    return to_string(x);
};

template<typename T>
int AbstractTableModel<T>::getNumberOfRows() {
    return entities->size();
}

template<typename T>
int AbstractTableModel<T>::getNumberOfColumns() {
    return nuColumns;
}

template<typename T>
T AbstractTableModel<T>::at(size_t index) {
    return this->entities->at(index);
}

template<typename T>
vector<T> *AbstractTableModel<T>::getEntities() const {
    return entities;
}

template<typename T>
void AbstractTableModel<T>::setEntities(vector<T> *entities) {
    AbstractTableModel::entities = entities;
}

template<typename T>
AbstractTableModel<T>::~AbstractTableModel() {

}

template class AbstractTableModel<Business*>;
template class AbstractTableModel<Department*>;
template class AbstractTableModel<Worker*>;