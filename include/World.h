//
// Created by henri kerch on 13/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_WORLD_H
#define INC_2022_PROJECT_HENREY_T_WORLD_H

#include<unistd.h>
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
    void simulate();


    const Player & getPlayer() const;
    void setPlayer(const Player &player);
};



#endif //INC_2022_PROJECT_HENREY_T_WORLD_H
