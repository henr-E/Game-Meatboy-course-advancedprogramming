//
// Created by henri kerch on 13/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_GAME_H
#define INC_2022_PROJECT_HENREY_T_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "World.h"
///The code using namespace sf; enables us to omit the prefix sf:: from everywhere in our code.
using namespace sf;
using namespace std;

class Game {
private:
    ///window
    VideoMode gameVideoMode;
    RenderWindow gameWindow;
    /*
     * Texture = image that we use to map on a 2D entity
     * entity + texture = sprite
     * more explanation about sprite and texture on:
     * https://www.sfml-dev.org/tutorials/2.5/graphics-sprite.php
     */
    Texture textureBackground;
    Sprite spriteBackground;
    Font font;
    SoundBuffer buffer;
    Sound sound;

    Player player;
    Sprite spritePlayer;
    Texture texturePlayer;

    World world;

    KeyboardInput keyboardInput;

public:
    ///game constructor
    Game();

    void draw();
    void start();
    KeyboardInput userInput(Event event);
};



#endif //INC_2022_PROJECT_HENREY_T_GAME_H
