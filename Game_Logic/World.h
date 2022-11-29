//
// Created by henri kerch on 13/11/2022.
//
#pragma once

#ifndef INC_2022_PROJECT_HENREY_T_WORLD_H
#define INC_2022_PROJECT_HENREY_T_WORLD_H

#include <vector>
#include <iostream>

#include "Player.h"
#include "Stopwatch.h"

using namespace std;
using namespace chrono;

class World {
private:
    Player player;
    Stopwatch stopwatch;

public:
    World();


    void keyboardToPlayer(KeyboardInput keyboardInput);
    void simulate(Collision c);


    const Player & getPlayer() const;
    void setPlayer(const Player &player);
};



#endif //INC_2022_PROJECT_HENREY_T_WORLD_H
