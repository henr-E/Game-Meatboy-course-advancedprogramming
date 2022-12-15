//
// Created by henri kerch on 04/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_ABSTRACTFACTORY_H
#define INC_2022_PROJECT_HENREY_T_ABSTRACTFACTORY_H

#include "Models/PlayerModel.h"
#include "Models/GoalModel.h"
#include "Models/WallModel.h"

class AbstractFactory{
public:
    /**
     * default constructor
     */
    AbstractFactory() = default;
    virtual ~AbstractFactory() {}
    virtual shared_ptr<PlayerModel> createPlayer() = 0;
    virtual shared_ptr<GoalModel> createGoal(inputRectangles tile) = 0;
    virtual shared_ptr<WallModel> createWall(inputRectangles tile) = 0;
};


#endif // INC_2022_PROJECT_HENREY_T_ABSTRACTFACTORY_H