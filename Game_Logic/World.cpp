//
// Created by henri kerch on 13/11/2022.
//

#include "World.h"


World::World() {}

void World::keyboardToPlayer(KeyboardInput keyboardInput){
    player.updateFromKeyboard(keyboardInput);
}

void World::simulate(Collision collision){
    //calculate elapsed time
    auto diff = steady_clock::now() - stopwatch.getPrevTime();
    auto nanoseconds = duration_cast<chrono::nanoseconds>(diff);
    auto nanosecondsAsInt = nanoseconds.count();

    stopwatch.setPrevTime(steady_clock::now());
    float seconds = nanosecondsAsInt/(float)1000000000;
//    cout << seconds <<endl;

    player.simulate(seconds, collision);
}
const Player & World::getPlayer() const{
    return player;
}

void World::setPlayer(const Player &player) {
    World::player = player;
}




