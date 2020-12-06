#ifndef CPP_UNIVERSITY_ASSIGMENT_CSVFORMATTER_H
#define CPP_UNIVERSITY_ASSIGMENT_CSVFORMATTER_H

#include <string>
#include <vector>

#include "CsvFormatterUtil.h"

using namespace std;
template <typename T>
class CsvFormatter : public CsvFormatterUtil {
public:

    virtual string Serialize() = 0;
    virtual void Parse(T parameters) = 0;
};


#endif
