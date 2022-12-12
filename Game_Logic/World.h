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

    PlayerModel player;
    WallModel wall;
    GoalModel goal;

    vector<vector<WallModel>> tiles;
    float tileSize;

public:

    void setUp(vector<vector<WallModel>>& tiles);
    void checkCollisionWithTiles();
    void checkCollisionWallsBotom();

    void keyboardToPlayer(KeyboardInput keyboardInput);

    void updatePlayerModel();
    void updateViews();

    void setAbstractFactory(const shared_ptr<AbstractFactory>& abstractFactory);

    void setScreenDimensions(const Position& screenDimensions);
    void setTileSize(float tileSize);
};



#endif //INC_2022_PROJECT_HENREY_T_WORLD_H
