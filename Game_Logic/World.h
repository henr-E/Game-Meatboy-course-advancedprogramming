//
// Created by henri kerch on 13/11/2022.
//
#pragma once

#ifndef INC_2022_PROJECT_HENREY_T_WORLD_H
#define INC_2022_PROJECT_HENREY_T_WORLD_H

#include <vector>
#include <iostream>
#include <cmath>

#include "AbstractFactory.h"

#include "Models/GoalModel.h"
#include "Models/PlayerModel.h"
#include "Models/WallModel.h"


#include "Stopwatch.h"
#include "structures_enums_std_include.h"

using namespace std;
using namespace chrono;

class World {
private:

    Position screenDimensions;
    Collision collision;

    shared_ptr<Stopwatch> stopwatch = Stopwatch::getInstance();
    shared_ptr<AbstractFactory> abstractFactory;

    shared_ptr<PlayerModel> player;
    vector<vector<shared_ptr<WallModel>>> walls;
    shared_ptr<GoalModel> goal;


    float tileSize;

public:
    World();
    virtual ~World();
    /**
     * create player, goal and walls
     * @param tiles
     */
    void setUp(vector<vector<inputRectangles>> tiles);
    /**
     * check Collision with Tiles
     */
    void checkCollisionWithTiles();
    /**
     * check Collision with walls and botom
     */
    void checkCollisionWallsBotom();

    /**
     * the world passes the keyboardinput to the player
     * @param keyboardInput
     */
    void keyboardToPlayer(KeyboardInput keyboardInput);

    /**
     * resets collision and checks new collisions
     * calculate elapsed time and  update the playerModel
     */
    void updatePlayerModel();
    /**
     * update view of wall, goal and player
     */
    void updateViews();

    /**
     * a setter for abstract factory
     * the levelstate passes a concrete factory to the world
     * the world then uses this factory as an abstract factory to create player, goal and walls
     * when the world calls the creating of player, goal and walls, the concrete factory makes these
     * this way the world can create these models without having to do anything with sfml
     * @param abstractFactory
     */
    void setAbstractFactory(const shared_ptr<AbstractFactory>& abstractFactory);

    /**
     * sets the screendimentions
     * @param screenDimensions
     */
    void setScreenDimensions(const Position& screenDimensions);
    /**
     * sets the tileSize
     * @param tileSize
     */
    void setTileSize(float tileSize);

    const shared_ptr<PlayerModel>& getPlayer() const;
    const shared_ptr<GoalModel>& getGoal() const;
};



#endif //INC_2022_PROJECT_HENREY_T_WORLD_H
