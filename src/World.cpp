//
// Created by henri kerch on 13/11/2022.
//

#include "World.h"

void World::simulate(Event event){
        userInput(event);
}

bool World::userInput(Event event)
{
    if (event.type == Event::KeyPressed)
    {
        // Escape
        if (event.key.code == Keyboard::Escape)
            return false;

        // Left arrow
        if (event.key.code == Keyboard::Left)
            player.moveLeft();

        // Right arrow
        if (event.key.code == Keyboard::Right)
           player.moveRight();
    }

    if (event.type == Event::KeyReleased)
    {
        // Left arrow
        if (event.key.code == Keyboard::Left)
            player.stopLeft();

        // Right arrow
        if (event.key.code == Keyboard::Right)
           player.stopRight();
    }
    return true;
}

void World::update(double seconds){
    player.update(seconds);
}
const Player & World::getPlayer() const{
    return player;
}



