//
// Created by henri kerch on 08/12/2022.
//
#include "ConcreteFactory.h"

PlayerModel ConcreteFactory::createPlayer() {
    //make a playerModel
    PlayerModel player;
    //make an observer and give the observer the playermodel
    shared_ptr<ownView::View> playerObserver = make_shared<PlayerView>(player);
    //add the observer to the playerModel
    player.addObserver(playerObserver);
    return player;
}
GoalModel ConcreteFactory::createGoal() {
    GoalModel goal;
//    shared_ptr<GoalModel> goal = make_shared<GoalModel>();
    shared_ptr<ownView::View> goalObserver = make_shared<GoalView>(goal);
    goal.addObserver(goalObserver);
    return goal;
}
WallModel ConcreteFactory::createWalls(vector<vector<WallModel>> tiles) {
    WallModel wall;
//    shared_ptr<WallModel> wall = make_shared<WallModel>();
    shared_ptr<ownView::View> wallObserver = make_shared<WallView>(wall, tiles);
    wall.addObserver(wallObserver);
    return wall;
}
ConcreteFactory::ConcreteFactory(const shared_ptr<RenderWindow>& sfWindow) : sfWindow(sfWindow) {}
