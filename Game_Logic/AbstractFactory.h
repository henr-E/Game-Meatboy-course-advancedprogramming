//
// Created by henri kerch on 04/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_ABSTRACTFACTORY_H
#define INC_2022_PROJECT_HENREY_T_ABSTRACTFACTORY_H

#include "Models/GoalModel.h"
#include "Models/PlayerModel.h"
#include "Models/WallModel.h"

class AbstractFactory {
public:
    /**
     * default constructor
     */
    AbstractFactory() = default;
    /**
     * destructor
     */
    virtual ~AbstractFactory() = default;
    virtual shared_ptr<PlayerModel> createPlayer() = 0;
    virtual shared_ptr<GoalModel> createGoal(ownType::inputRectangles tile) = 0;
    virtual shared_ptr<WallModel> createWall(ownType::inputRectangles tile) = 0;
};

#endif // INC_2022_PROJECT_HENREY_T_ABSTRACTFACTORY_H