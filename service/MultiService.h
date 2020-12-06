//
// Created by filipz on 12/6/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_MULTISERVICE_H
#define CPP_UNIVERSITY_ASSIGMENT_MULTISERVICE_H

#include "Service.h"
template <typename T,typename Y>

class MultiService : public Service<T> {
protected:
    Y serviceDependency;
public:
    MultiService(const string &filename, vector<T> *entities, const Y &serviceDependency);
};

#endif //CPP_UNIVERSITY_ASSIGMENT_MULTISERVICE_H
