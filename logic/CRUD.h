#ifndef CPP_UNIVERSITY_ASSIGMENT_CRUD_H
#define CPP_UNIVERSITY_ASSIGMENT_CRUD_H

#include <util/Util.h>
#include "../service/Service.h"

using namespace cuaUtil;

template <typename T>
class CRUD {
protected:
    Service<T> *const service; //saljemo worker service ovde
    void deleteEntity(const long index) const;
    void replace(const long index,T entity);
    void addEntity(const T entity) const;
public:
    CRUD<T>(Service<T> *service);

    virtual void createEntity(const T entity) = 0;
    virtual void replaceEntity(T entity) = 0;
    virtual void removeEntity(const long id) = 0;
    void readEntities();

    Service<T> *const getService() const;
};

#endif
