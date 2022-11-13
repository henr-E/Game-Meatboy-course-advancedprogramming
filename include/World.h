//
// Created by henri kerch on 13/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_WORLD_H
#define INC_2022_PROJECT_HENREY_T_WORLD_H



#include "Stopwatch.h"
#include "Player.h"

class World {
private:

    Stopwatch time;
    Player player;

public:
    void simulate(Event event);
    bool userInput(Event event);
    void update(double seconds);
    const Player & getPlayer() const;
};



#endif //INC_2022_PROJECT_HENREY_T_WORLD_H
