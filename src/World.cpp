//
// Created by henri kerch on 13/11/2022.
//

#include "World.h"


World::World() {}

void World::keyboardToPlayer(KeyboardInput keyboardInput){
    player.updateFromKeyboard(keyboardInput);
}

void World::simulate(float seconds){
    player.simulate(seconds);
}
const Player & World::getPlayer() const{
    return player;
}

void World::setPlayer(const Player &player) {
    World::player = player;
}




