//
// Created by henri kerch on 08/12/2022.
//
#include "ConcreteFactory.h"

shared_ptr<PlayerModel> ConcreteFactory::createPlayer() {
    //make a playerModel
    shared_ptr<PlayerModel> player = make_shared<PlayerModel>();

    Position leftUpper(-1, -1 + 26.f/272.f);
    Position rightDown(-1 + 26.f/272.f, -1);

    player->setTileType(PLAYER);
    player->setRightDownCorner(rightDown);
    player->setLeftUpperCorner(leftUpper);
    player->setTileHeightWidth(26.f/272.f);

    //make an observer and give the observer the playermodel
    shared_ptr<ownView::View> playerObserver = make_shared<PlayerView>(player->getLeftUpperCorner(), PLAYER, sfWindow);
    //add the observer to the playerModel
    player->addObserver(playerObserver);
    return player;
}
shared_ptr<GoalModel> ConcreteFactory::createGoal(inputRectangles tile) {
    shared_ptr<GoalModel> goal = make_shared<GoalModel>();

    goal->setTileType(GIRL);
    goal->setRightDownCorner(tile.rightDownCorner);
    goal->setLeftUpperCorner(tile.leftUpperCorner);
    goal->setTileHeightWidth(tile.tileHeightWidth);

    shared_ptr<ownView::View> goalObserver = make_shared<GoalView>(goal->getLeftUpperCorner(), GIRL, sfWindow);
    goal->addObserver(goalObserver);
    return goal;
}
shared_ptr<WallModel> ConcreteFactory::createWall(inputRectangles tile) {
    shared_ptr<WallModel> wall = make_shared<WallModel>();

    wall->setTileType(tile.tileType);
    wall->setRightDownCorner(tile.rightDownCorner);
    wall->setLeftUpperCorner(tile.leftUpperCorner);
    wall->setTileHeightWidth(tile.tileHeightWidth);

//todo zet in verslag dat ik het logisch vond om de positie gewoon in de constructor van de view mee te geven want
    //todo de positie van walls veranderd nooit dus update is overbodig
    shared_ptr<ownView::View> wallObserver = make_shared<WallView>(wall->getLeftUpperCorner(), wall->getTileType(), sfWindow);
    wall->addObserver(wallObserver);
    return wall;
}
ConcreteFactory::ConcreteFactory(const shared_ptr<RenderWindow>& sfWindow) : sfWindow(sfWindow) {}
ConcreteFactory::~ConcreteFactory() {}




