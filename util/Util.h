#ifndef CPP_UNIVERSITY_ASSIGMENT_UTIL_H
#define CPP_UNIVERSITY_ASSIGMENT_UTIL_H

#include "string"
#include "vector"

using namespace std;

namespace cuaUtil {
    void parseStringIntoVector(string &target, vector<string> &vectorStrings,string sep);

    //Pointers in vectors template
    template <typename T> // must be defined in header because c++
    long findIndex(const long &id,vector<T> *toSearch) {
        long index = -1;
        size_t i = 0;
        for (T entity : (*toSearch)) {
            if (entity->getId() == id){
                index = i;
                break;
            }
            i++;
        }
        return index;
    }
}


#endif //CPP_UNIVERSITY_ASSIGMENT_UTIL_H
