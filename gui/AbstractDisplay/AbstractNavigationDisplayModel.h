#ifndef CPP_UNIVERSITY_ASSIGMENT_ABSTRACTNAVIGATIONDISPLAYMODEL_H
#define CPP_UNIVERSITY_ASSIGMENT_ABSTRACTNAVIGATIONDISPLAYMODEL_H

#include <FL/Fl_Group.H>
#include <vector>
#include "string"

using namespace std;

template <typename T>
class AbstractNavigationDisplayModel {
protected:
    int currentIndex = 0;
    T currentEntity;
    vector<T> *entities;
public:
    AbstractNavigationDisplayModel(T currentEntity, vector<T> *entities);
    virtual ~AbstractNavigationDisplayModel();

    virtual Fl_Group *createDetailsDisplay() = 0;
    virtual void updateDetailDisplay() = 0;

    virtual std::string getMainDisplayText() = 0;
    std::string getQueueDisplayText();

    int size();
    bool canIncreaseIndex();
    bool canDecreaseIndex();
    T nextEntity();
    T prevEntity();
};

#endif
