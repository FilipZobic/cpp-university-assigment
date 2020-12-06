#include <model/Business.h>
#include "MultiService.h"
#include "DepartmentService.h"

template<typename T, typename Y>
MultiService<T, Y>::MultiService(const string &filename, vector<T> *entities, const Y &serviceDependency)
        :Service<T>(filename, entities), serviceDependency(serviceDependency) {}

template class MultiService<Business*,DepartmentService*>;