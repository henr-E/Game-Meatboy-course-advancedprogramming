//
// Created by henri kerch on 04/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_CONCRETEFACTORY_H
#define INC_2022_PROJECT_HENREY_T_CONCRETEFACTORY_H
#include "../Game_Logic/AbstractFactory.h"
class ConcreteFactory: public AbstractFactory {
public:
    virtual void createPlayer(World& world);
};

#endif // INC_2022_PROJECT_HENREY_T_CONCRETEFACTORY_H
