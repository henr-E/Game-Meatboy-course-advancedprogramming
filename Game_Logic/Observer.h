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
    /**
     * constructor
     */
    Observer() = default;
    /**
     * destructor
     */
    virtual ~Observer() = default;
    /**
     * update the observer
     */
    virtual void update() = 0;
    /**
     * updates the data
     * @param position
     * @param direction
     */
    virtual void updateData(ownType::Position position, ownType::Direction direction) = 0;
};

#endif // INC_2022_PROJECT_HENREY_T_OBSERVER_H
