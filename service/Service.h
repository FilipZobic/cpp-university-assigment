#ifndef CPP_UNIVERSITY_ASSIGMENT_SERVICE_H
#define CPP_UNIVERSITY_ASSIGMENT_SERVICE_H

#include <string>
#include <vector>
#include <fstream>
#include <util/Util.h>
#include "../model/Worker.h"
#include "iostream"
using namespace std;

template <typename T>
class Service {

private:
    ifstream& readFirstLine(ifstream& stream);
    void readAllLines(vector<string>& lines,ifstream &file);
    void writeAllLines(ofstream &file) const;
    template<typename Y>
    void openFile(Y &file);

protected:
    string filename;
    int amountOfItems;
    long lastUsedId;
    vector<T> *entities;
    vector<string> readFromFile(); //reads all entities to vector calls parseEntity() and sets amountOfItems and lastUsedIde creates entities here

public:
    Service(const string &filename,vector<T>* entities);
    void writeToFile(); //calls serilizatin and replaces everything in file each line with vector and amount and last usedid
    virtual void parseAllEntities() = 0;
    virtual void parseEntity(T *entity,vector<string> &paramsForObject) = 0;

    void printArr(){
        for (T i : (*entities)) {
            cout << i->Serialize() << endl;
        }
    }

    const string &getFilename() const;

    void setFilename(const string &filename);

    int getAmountOfItems() const;

    void setAmountOfItems(int amountOfItems);

    long getLastUsedId() const;

    void setLastUsedId(long lastUsedId);

    vector<T> *getEntities() const;

    void setEntities(vector<T> *entities);

    void clearMemory(const long id);

    long findIndex(long id) const;

    void addToVector(T entity){
        this->entities->push_back(entity);
    }
};

#endif
