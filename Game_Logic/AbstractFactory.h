//
// Created by henri kerch on 04/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_ABSTRACTFACTORY_H
#define INC_2022_PROJECT_HENREY_T_ABSTRACTFACTORY_H

#include "World.h"

class AbstractFactory{
public:
    virtual void createPlayer(World& world) = 0;
};


#endif // INC_2022_PROJECT_HENREY_T_ABSTRACTFACTORY_H