#include <model/Business.h>
#include "MultiService.h"
#include "DepartmentMultiService.h"

template<typename T, typename Y>
MultiService<T, Y>::MultiService(const string &filename, vector<T> *entities, const Y &serviceDependency)
        :Service<T>(filename, entities), serviceDependency(serviceDependency) {}

template class MultiService<Business*,DepartmentMultiService*>;
template class MultiService<Department*,WorkerService*>;