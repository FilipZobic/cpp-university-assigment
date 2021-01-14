#ifndef CPP_UNIVERSITY_ASSIGMENT_ABSTRACTTABLEMODEL_H
#define CPP_UNIVERSITY_ASSIGMENT_ABSTRACTTABLEMODEL_H

#include <vector>
#include <string>

using namespace std;

template <typename T>
class AbstractTableModel {

protected:
    int nuColumns;
    vector<T> *entities;

public:

    AbstractTableModel(int nuColumns, vector<T> *entities);
    virtual ~AbstractTableModel();

    virtual string getColumnHeader(int y) = 0;
    virtual string getCellValue(int x, int y) = 0;

    string getRowHeader(int x);
    int getNumberOfRows();
    int getNumberOfColumns();
    T at(size_t index);

    vector<T> *getEntities() const;
    void setEntities(vector<T> *entities);
};


#endif