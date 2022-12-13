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
    AbstractFactory() = default;
    virtual PlayerModel createPlayer() = 0;
    virtual GoalModel createGoal() = 0;
    virtual WallModel createWalls(vector<vector<WallModel>> tiles) = 0;
};


#endif // INC_2022_PROJECT_HENREY_T_ABSTRACTFACTORY_H