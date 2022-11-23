//
// Created by henri kerch on 13/11/2022.
//
#pragma once

#ifndef INC_2022_PROJECT_HENREY_T_GAME_H
#define INC_2022_PROJECT_HENREY_T_GAME_H

#include <vector>
#include <fstream>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../../Game_Logic/World.h"
#include "../InputToGame/InputParser.h"
#include "../InputToGame/TileMap.h"

using namespace sf;
using namespace std;

class Game {
private:
    //sfml elements
    VideoMode sfVideoMode;
    RenderWindow sfWindow;
    SoundBuffer buffer;
    Sound sound;
    Music music;

    Vector2i screenDimensions;

    //sfml elements
    Sprite spritePlayer;
    Texture texturePlayer;

    //selfmade classes/structs
    KeyboardInput keyboardInput;
    InputParser inputParser;
    TileMap tileMap;
    World world;

    Text t;

    //variables
    int chosenLevel;

public:
    Game();
    int simulate();
    void userInput(Event event);
    void setChosenLevel(int chosenLevel);
    void drawPlayerWin();
};



#endif //INC_2022_PROJECT_HENREY_T_GAME_H
