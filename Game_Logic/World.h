//
// Created by henri kerch on 13/11/2022.
//
#pragma once

#ifndef INC_2022_PROJECT_HENREY_T_WORLD_H
#define INC_2022_PROJECT_HENREY_T_WORLD_H

#include <vector>
#include <iostream>

#include <cmath>

#include "Player.h"
#include "Rectangle.h"
#include "Stopwatch.h"

using namespace std;
using namespace chrono;

class World {
private:
    Player player;
    shared_ptr<Stopwatch> stopwatch = Stopwatch::getInstance();

    Collision collision;

public:
    World();

    void checkCollisionWithTiles(const vector<vector<Rectangle>> &tiles);
    void checkCollisionWallsBotom();

    void keyboardToPlayer(KeyboardInput keyboardInput);
    void simulate(vector<vector<Rectangle>> tiles);

    const Player & getPlayer() const;
    void setPlayer(const Player &player);
};



#endif //INC_2022_PROJECT_HENREY_T_WORLD_H
