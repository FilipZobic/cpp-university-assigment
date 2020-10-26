//
// Created by filipz on 10/25/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_SERVICE_H
#define CPP_UNIVERSITY_ASSIGMENT_SERVICE_H

#include <string>
#include <vector>
#include <fstream>
#include "../model/Worker.h"
#include "iostream"
using namespace std;

template <typename T>
class Service {
private:
    string filename;
    int amountOfItems;
    long lastUsedId;
    vector<T> *entities;
public:
    Service(const string &filename,vector<T>* entities);
    ifstream& readFirstLine(ifstream& stream);
    void readFromFile() /*= 0*/; //reads all entities to vector calls parseEntity() and sets amountOfItems and lastUsedIde creates entities here
    void writeToFile()  /*= 0*/; //calls serilizatin and replaces everything in file each line with vector and amount and last usedid
    void parseEntity(T entity,string &entityString) /*= 0*/;

    template<typename Y>
    void openFile(Y &file);
    void readAllLines(vector<string>& lines,ifstream &file);
    void writeAllLines(ofstream &file) const;
    void printArr(){
        for (T i : (*entities)) {
            cout << i->Serialize() << endl;
        }
    }
};


#endif //CPP_UNIVERSITY_ASSIGMENT_SERVICE_H
