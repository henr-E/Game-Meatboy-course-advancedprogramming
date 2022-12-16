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
    /**
     * constructor
     * @param sfWindow
     */
    explicit ConcreteFactory(const shared_ptr<RenderWindow>& sfWindow);
    /**
     * destructor
     */
    ~ConcreteFactory() override;
    /**
     * creates a playerModel with a Playerview
     * @return playerModel
     */
    shared_ptr<PlayerModel> createPlayer() override;
    /**
     * creates a goalModel with a goalView
     * @return goalModel
     */
    shared_ptr<GoalModel> createGoal(inputRectangles tile) override;
    /**
     * creates a wallModel with a wallView
     * @return wallModel
     */
    shared_ptr<WallModel> createWall(inputRectangles tile) override;


};

#endif // INC_2022_PROJECT_HENREY_T_CONCRETEFACTORY_H
