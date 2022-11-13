//
// Created by henri kerch on 13/11/2022.
//

#ifndef INC_2022_PROJECT_HENREY_T_GAME_H
#define INC_2022_PROJECT_HENREY_T_GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Stopwatch.h"
#include "World.h"

///The code using namespace sf; enables us to omit the prefix sf:: from everywhere in our code.
using namespace sf;

class Game {
private:
    ///window
    VideoMode gameVideoMode;
    RenderWindow gameWindow;

    Texture textureBackground;
    Sprite spriteBackground;

    World world;

    void draw();

public:
    ///game constructor
    Game();

    ///
    void start();
};



#endif //INC_2022_PROJECT_HENREY_T_GAME_H
