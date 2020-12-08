//
// Created by filipz on 12/8/20.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_ENTITY_H
#define CPP_UNIVERSITY_ASSIGMENT_ENTITY_H


class Entity {
public:
    virtual long getId() = 0;

};
// business department person implements it and it calls their unique id we use it in Util.findindex getId

#endif //CPP_UNIVERSITY_ASSIGMENT_ENTITY_H
