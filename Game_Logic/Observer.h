//
// Created by henri kerch on 08/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_OBSERVER_H
#define INC_2022_PROJECT_HENREY_T_OBSERVER_H

#include "memory"
#include "structures_enums_std_include.h"
using namespace std;

class Observer {
public:
    Observer() = default;
    virtual ~Observer() {}
    virtual void update() = 0;
    virtual void updateData(Position position, Direction direction) = 0;
};

#endif // INC_2022_PROJECT_HENREY_T_OBSERVER_H
