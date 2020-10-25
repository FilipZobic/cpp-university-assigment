//
// Created by filipz on 10/24/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_CSVFORMATTER_H
#define CPP_UNIVERSITY_ASSIGMENT_CSVFORMATTER_H

#include <string>
#include <vector>

using namespace std;
class CsvFormatter {
public:
    const static string sep;
    virtual string Serialize() = 0;
    virtual void Parse(vector<string>* parameters) = 0;
};


#endif //CPP_UNIVERSITY_ASSIGMENT_CSVFORMATTER_H
