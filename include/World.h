//
// Created by henri kerch on 13/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_WORLD_H
#define INC_2022_PROJECT_HENREY_T_WORLD_H



#include "Player.h"

class World {
private:
    Player player;

public:
    World();


    void keyboardToPlayer(KeyboardInput keyboardInput);
    void simulate(double seconds);


    const Player & getPlayer() const;
    void setPlayer(const Player &player);
};



#endif //INC_2022_PROJECT_HENREY_T_WORLD_H
