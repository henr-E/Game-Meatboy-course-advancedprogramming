//
// Created by henri kerch on 13/11/2022.
//
#pragma once

#ifndef INC_2022_PROJECT_HENREY_T_GAME_H
#define INC_2022_PROJECT_HENREY_T_GAME_H

#include <fstream>
#include <iostream>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "States/StateManager.h"

using namespace sf;
using namespace std;

class Game {
private:
    // sfml elements
    VideoMode sfVideoMode;
    shared_ptr<RenderWindow> sfWindow = make_shared<RenderWindow>();

    shared_ptr<StateManager> stateManager;
    ownType::FunctionCallTo functionCallTo;

    SoundBuffer buffer;
    Sound sound;
    Music music;

    Vector2i windowDimentions;

public:
    /**
     * constructor
     */
    Game();
    /**
     * destructor
     */
    virtual ~Game() = default;
    /**
     * run the game
     */
    void run();
};

#endif // INC_2022_PROJECT_HENREY_T_GAME_H
