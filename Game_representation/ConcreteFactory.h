//
// Created by henri kerch on 04/12/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_CONCRETEFACTORY_H
#define INC_2022_PROJECT_HENREY_T_CONCRETEFACTORY_H

#include "../Game_Logic/AbstractFactory.h"
#include "../Game_Logic/Observer.h"
#include "Views/GoalView.h"
#include "Views/PlayerView.h"
#include "Views/View.h"
#include "Views/WallView.h"
#include "memory.h"
class ConcreteFactory: public AbstractFactory {
private:
    shared_ptr<RenderWindow> sfWindow;

public:

    explicit ConcreteFactory(const shared_ptr<RenderWindow>& sfWindow);
    ~ConcreteFactory() override;
    shared_ptr<PlayerModel> createPlayer() override;
    shared_ptr<GoalModel> createGoal(inputRectangles tile) override;
    shared_ptr<WallModel> createWall(inputRectangles tile) override;


};

#endif // INC_2022_PROJECT_HENREY_T_CONCRETEFACTORY_H
